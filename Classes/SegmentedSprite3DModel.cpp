#include "SegmentedSprite3DModel.h"
#include <string>
#include "StringUtils.h"
#include "OBJ.h"
#include "GenUtils.h"

using namespace cocos2d;
using namespace std;

SegmentedSprite3DModel* SegmentedSprite3DModel::create(const char* inputFile, const OBJ* instanceShape, Texture2D* texture)
{
	const int numPoints = 2000; // TODO Set this later
	Vec3* positions = new Vec3[numPoints];
	Vec2* texCoords = new Vec2[numPoints];

	Data data = FileUtils::getInstance()->getDataFromFile(inputFile);
	if (!data.isNull())
	{
		string str((char*)(data.getBytes()));
		bop::StringDelimiter lines = bop::StringDelimiter(bop::StringUtils::ConvertToUnixLineEndings(str), '\n');
		int lineNo = 0;
		// for each pixel
		while (lines.hasNext())
		{
			// definitely some room for improvement here.
			float x = 0;
			float y = 0;
			float z = 0;
			float tx = 0;
			float ty = 0;
			bool success = false;
			bop::StringDelimiter coordinates = bop::StringDelimiter(lines.getNext(), ' ');
			if (coordinates.hasNext())
			{
				x = atof(coordinates.getNext().c_str());
				if (coordinates.hasNext())
				{
					y = atof(coordinates.getNext().c_str());
					if (coordinates.hasNext())
					{
						z = atof(coordinates.getNext().c_str());
						if (coordinates.hasNext())
						{
							tx = atof(coordinates.getNext().c_str());
							if (coordinates.hasNext())
							{
								ty = atof(coordinates.getNext().c_str());
								success = true;
							}
						}
					}
				}
			}
			if (!success)
			{
				CCLOG("BoP: warning: invalid input in file %s, line %d.", inputFile, lineNo + 1);
			}
			else
			{
				positions[lineNo] = Vec3(x, y, z);
				texCoords[lineNo] = Vec2(tx, ty);
				lineNo++;
			}
		}

		// Vertices
		const vector<OBJ::Vertex>& objVertices = instanceShape->getVertices();
		Vec3* instanceVertices = new Vec3[objVertices.size()];
		for (unsigned i = 0; i < objVertices.size(); i++)
		{
			instanceVertices[i] = Vec3(objVertices[i].vx, objVertices[i].vy, objVertices[i].vz);
		}

		// Triangles
		const vector<OBJ::Triangle>& objTriangles = instanceShape->getTriangles();
		vector<int> triangulation;
		for (unsigned i = 0; i < objTriangles.size(); i++)
		{
			triangulation.push_back(objTriangles[i].v1);
			triangulation.push_back(objTriangles[i].v2);
			triangulation.push_back(objTriangles[i].v3);
		}

		auto glProgram = GLProgram::createWithFilenames("shaders/morph.vert", "shaders/morph.frag");
		auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
		glProgramState->setUniformTexture("u_texture", texture);
		glProgramState->setUniformVec3v("u_positions", numPoints, positions);
		glProgramState->setUniformVec2v("u_texCoords", numPoints, texCoords);
		glProgramState->setUniformVec3v("u_instanceVertexPositions", objVertices.size(), instanceVertices);

		SegmentedSprite3DModel* model = new SegmentedSprite3DModel();
		if (model)
		{
			// Construct our mesh
			auto mesh = GenUtils::CreateGeometryInstancedMesh(lineNo, objVertices.size(), triangulation);
			model->_positions = positions;
			model->_texCoords = texCoords;
			model->_instanceVertices = instanceVertices;
			model->setTexture(texture);
			model->addMesh(mesh);
			model->setGLProgramState(glProgramState);
			model->_contentSize = model->getBoundingBox().size;
			model->autorelease();
			return model;
		}
	}
	return nullptr;
}
