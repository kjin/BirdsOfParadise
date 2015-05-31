#include "PlayerModel.h"
#include "cocos2d.h"
#include "GenUtils.h"

using namespace cocos2d;

PlayerModel* PlayerModel::create()
{
	auto cube = Sprite3D::create("models/halfUnitCube.obj");
	OBJ* obj = GenUtils::Cocos2dMeshToOBJ(cube->getMesh());

	PlayerModel* model = new PlayerModel();
	if (model->init("data/plane.txt", obj, Director::getInstance()->getTextureCache()->addImage("textures/plane.png")))
	{
		return model;
	}
	else
	{
		model->release();
		delete model;
		return nullptr;
	}
}
