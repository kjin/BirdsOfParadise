#include "Sprite3DModel.h"
#include <string>
#include "StringUtils.h"
#include "OBJ.h"
#include "GenUtils.h"

using namespace cocos2d;
using namespace std;

Sprite3DModel* Sprite3DModel::createFromFile(const char* fileName)
{
	const int numPoints = 2000; // TODO Set this later
	Vec3* positions = new Vec3[numPoints];
	Vec2* texCoords = new Vec2[numPoints];

	Data data = FileUtils::getInstance()->getDataFromFile(fileName);
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
				CCLOG("BoP: warning: invalid input in file %s, line %d.", fileName, lineNo + 1);
			}
			positions[lineNo] = Vec3(x, y, z);
			texCoords[lineNo] = Vec2(tx, ty);
			lineNo++;
		}

		// Make a good triangulation. Let's start with a quad.
		vector<int> triangulation;
		triangulation.push_back(0);
		triangulation.push_back(1);
		triangulation.push_back(2);
		triangulation.push_back(2);
		triangulation.push_back(3);
		triangulation.push_back(0);

		// temporary
		auto texture = Director::getInstance()->getTextureCache()->addImage("textures/test.png");

		auto glProgram = GLProgram::createWithFilenames("shaders/morph.vert", "shaders/morph.frag");
		auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
		glProgramState->setUniformTexture("u_texture", texture);
		glProgramState->setUniformVec3v("u_positions", numPoints, positions);
		glProgramState->setUniformVec2v("u_texCoords", numPoints, texCoords);

		Sprite3DModel* model = new Sprite3DModel(); //
		if (model)
		{
			// Construct our mesh
			auto mesh = GenUtils::CreateGeometryInstancedMesh(1793, 4, triangulation);
			model->_positions = positions;
			model->_texCoords = texCoords;
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
