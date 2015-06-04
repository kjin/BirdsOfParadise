#ifndef _BOP_MODEL_H_
#define _BOP_MODEL_H_

#include "cocos2d.h"

class Model : public cocos2d::Ref
{
protected:
	cocos2d::Vec3 _modelPosition;
	cocos2d::Vec3 _modelVelocity;
	float _modelDampeningFactor;
protected:
	bool init()
	{
		_modelPosition = cocos2d::Vec3(0, 0, 0);
		_modelVelocity = cocos2d::Vec3(0, 0, 0);
		_modelDampeningFactor = 1;
		return true;
	}
public:
	CREATE_FUNC(Model);

	// Gets the model's position.
	cocos2d::Vec3 getModelPosition() const { return _modelPosition; }
	// Sets the model's position.
	void setModelPosition(cocos2d::Vec3 modelPosition) { _modelPosition = modelPosition; }

	// Gets the model's velocity.
	cocos2d::Vec3 getModelVelocity() const { return _modelVelocity; }
	// Sets the model's velocity.
	void setModelVelocity(cocos2d::Vec3 modelVelocity) { _modelVelocity = modelVelocity; }
	// Adds to the model's velocity.
	void addToModelVelocity(cocos2d::Vec3 velocity) { _modelVelocity += velocity; }

	// Gets the model's dampening factor.
	float getModelDampneingFactor() const { return _modelDampeningFactor; }
	// Sets the model's dampening factor.
	void setModelDampeningFactor(float modelDampeningFactor) { _modelDampeningFactor = modelDampeningFactor; }

	void updateModel(float deltaTime)
	{
		_modelPosition += _modelVelocity;
		_modelVelocity *= _modelDampeningFactor;
	}
};

#endif