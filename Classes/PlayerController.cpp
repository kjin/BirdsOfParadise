// PlayerController
// Controls the player plane.

#include "PlayerController.h"
#include "GameState.h"
#include "InputState.h"
#include "Model.h"

using namespace cocos2d;

void PlayerController::update(float deltaTime)
{
	float acceleration = 0.5f;
	if (_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
	{
		_model->addToModelVelocity(Vec3(-acceleration, 0, 0));
	}
	if (_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
	{
		_model->addToModelVelocity(Vec3(acceleration, 0, 0));
	}
	if (_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
	{
		_model->addToModelVelocity(Vec3(0, -acceleration, 0));
	}
	if (_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_UP_ARROW))
	{
		_model->addToModelVelocity(Vec3(0, acceleration, 0));
	}
}