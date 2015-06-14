#include "PlayerView.h"
#include "cocos2d.h"
#include "GenUtils.h"

using namespace cocos2d;

PlayerView* PlayerView::createWithModel(const Model* model)
{
	auto cube = Sprite3D::create("models/halfUnitCube.obj");
	OBJ* obj = GenUtils::Cocos2dMeshToOBJ(cube->getMesh());

	PlayerView* view = new PlayerView();
	if (view->init(model, "data/plane.txt", obj, Director::getInstance()->getTextureCache()->addImage("textures/plane.png")))
	{
		return view;
	}
	else
	{
		view->release();
		delete view;
		return nullptr;
	}
}
