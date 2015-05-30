#include "Sprite3DModel.h"
#include <string>
#include "StringUtils.h"
#include "OBJ.h"
#include "GenUtils.h"

using namespace cocos2d;
using namespace std;

Sprite3DModel* Sprite3DModel::createFromFile(const char* fileName)
{
	OBJ obj(OBJ::Position | OBJ::Texture | OBJ::Normal);

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
				CCLOG("BoP warning: invalid input in file %s, line %d.", fileName, lineNo);
			}
			obj.addAABB(x, y, z, 1, 1, 1, tx, ty);
			lineNo++;
		}

		// temporary
		auto texture = Director::getInstance()->getTextureCache()->addImage("textures/test.png");

		auto glProgram = GLProgram::createWithFilenames("shaders/morph.vert", "shaders/morph.frag");
		auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);
		glProgramState->setUniformVec4("u_position", Vec4(0, 0, 0, 0));
		glProgramState->setUniformTexture("u_texture", texture);

		Sprite3DModel* model = new Sprite3DModel();
		if (model)
		{
			auto mesh = GenUtils::OBJToCocos2dMesh(obj);
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
