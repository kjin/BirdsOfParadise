#ifndef _BOP_CONTROLLER_H_
#define _BOP_CONTROLLER_H_

#include "cocos2d.h"

#define CONTROLLER_CREATE_FUNC(x) static x* create(const GameState* gameState, Model* model) { x* var = new x(); if (var != nullptr) { if (var->initWithModel(gameState, model)) { return var; } delete var; } return nullptr; }

class Model;
class GameState;

class Controller : public cocos2d::Ref
{
protected:
	const GameState* _gameState;
	Model* _model;
protected:
	bool initWithModel(const GameState* gameState, Model* model)
	{
		_gameState = gameState;
		_model = model;
		return true;
	}
public:
	virtual void update(float deltaTime) = 0;
};

#endif