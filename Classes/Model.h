#ifndef _BOP_MODEL_H_
#define _BOP_MODEL_H_

#include "cocos2d.h"

class Model
{
protected:
	cocos2d::Vec3 _modelPosition;
	cocos2d::Vec3 _modelVelocity;
	float _modelDampeningFactor;
public:
	Model()
		: _modelPosition(0, 0, 0), _modelVelocity(0, 0, 0), _modelDampeningFactor(1) {}

	// Gets the model's position.
	cocos2d::Vec3 getModelPosition() { return _modelPosition; }
	// Sets the model's position.
	void setModelPosition(cocos2d::Vec3 modelPosition) { _modelPosition = modelPosition; }

	// Gets the model's velocity.
	cocos2d::Vec3 getModelVelocity() { return _modelVelocity; }
	// Sets the model's velocity.
	void setModelVelocity(cocos2d::Vec3 modelVelocity) { _modelVelocity = modelVelocity; }
	// Adds to the model's velocity.
	void addToModelVelocity(cocos2d::Vec3 velocity) { _modelVelocity += velocity; }

	// Gets the model's dampening factor.
	float getModelDampneingFactor() { return _modelDampeningFactor; }
	// Sets the model's dampening factor.
	void setModelDampeningFactor(float modelDampeningFactor) { _modelDampeningFactor = modelDampeningFactor; }

	void updateModel(float deltaTime)
	{
		_modelPosition += _modelVelocity;
		_modelVelocity *= _modelDampeningFactor;
	}
};

#endif