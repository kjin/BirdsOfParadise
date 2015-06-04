#include "Sprite3DView.h"

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

void Sprite3DView::update(float deltaTime)
{
	setPosition3D(_model->getModelPosition());
}