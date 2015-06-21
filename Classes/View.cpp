#include "View.h"
#include "Model.h"

bool View::init(const Model* model, cocos2d::Node* node)
{
	_model = model;
	_sceneGraphNode = node;
	_sceneGraphNode->retain();
	return true;
}

View* View::create(const Model* model, cocos2d::Node* node)
{
	View* pRet = new View();
	if (pRet != nullptr && pRet->init(model, node))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	return nullptr;
}

View::~View()
{
	_sceneGraphNode->release();
}

void View::update(float deltaTime)
{
	if (_model->getModelHealth() > 0)
	{
		_sceneGraphNode->setVisible(true);
		_sceneGraphNode->setPosition3D(_model->getModelPosition());
	}
	else
	{
		_sceneGraphNode->setVisible(false);
	}
}
