#include "BirdsOfParadise/BoPPlaneView.h"
#include "cocos2d.h"
#include "GenUtils.h"

using namespace cocos2d;

PlaneView* PlaneView::createWithModel(const Model* model)
{
	auto cube = Sprite3D::create("models/halfUnitCube.obj");
	OBJ* obj = GenUtils::Cocos2dMeshToOBJ(cube->getMesh());

	PlaneView* view = new PlaneView();
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
