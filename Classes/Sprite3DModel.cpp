#include "Sprite3DModel.h"

bool Sprite3DModel::init()
{
	if (!Sprite3D::init())
	{
		return false;
	}
	scheduleUpdate();
	return true;
}

void Sprite3DModel::update(float deltaTime)
{
	Model::updateModel(deltaTime);
	setPosition3D(getModelPosition());
}