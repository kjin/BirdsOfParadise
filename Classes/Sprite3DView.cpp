#include "Sprite3DView.h"
#include "Model.h"

bool Sprite3DView::init()
{
	// use initWithModel instead.
	assert(false);
	return false;
}

bool Sprite3DView::initWithModel(const Model* model)
{
	if (!Sprite3D::init())
	{
		return false;
	}
	_model = model;
	scheduleUpdate();
	return true;
}

bool Sprite3DView::initWithModelAndFile(const Model* model, const std::string& modelPath)
{
	if (!Sprite3D::initWithFile(modelPath))
	{
		return false;
	}
	_model = model;
	scheduleUpdate();
	return true;
}

Sprite3DView* Sprite3DView::createWithModelAndFile(const Model* model, const std::string& modelPath)
{
	Sprite3DView* pRet = new Sprite3DView();
	if (pRet && pRet->initWithModelAndFile(model, modelPath))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	pRet = nullptr;
	return nullptr;
}

void Sprite3DView::update(float deltaTime)
{
	if (_model->getModelHealth() > 0)
	{
		setVisible(true);
		setPosition3D(_model->getModelPosition());
	}
	else
	{
		setVisible(false);
	}
}