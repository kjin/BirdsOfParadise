// PlayerController
// Controls the player plane.

#include "BoPPlayerController.h"
#include "BoPGameState.h"
#include "InputState.h"
#include "BoPPlaneModel.h"
#include "BoPTurret.h"

using namespace cocos2d;

void PlayerController::update(float deltaTime)
{
	float acceleration = 0.5f;
	PlaneModel* planeModel = (PlaneModel*)_model;
	const InputState* inputState = _gameState->getInputState();
	if (inputState->isKeyDown(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
	{
		planeModel->addToModelVelocity(Vec3(-acceleration, 0, 0));
	}
	if (inputState->isKeyDown(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
	{
		planeModel->addToModelVelocity(Vec3(acceleration, 0, 0));
	}
	if (inputState->isKeyDown(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
	{
		planeModel->addToModelVelocity(Vec3(0, -acceleration, 0));
	}
	if (inputState->isKeyDown(EventKeyboard::KeyCode::KEY_UP_ARROW))
	{
		planeModel->addToModelVelocity(Vec3(0, acceleration, 0));
	}

	for (size_t i = 0; i < planeModel->getNumTurrets(); i++)
	{
		Turret* turret = planeModel->getTurret(i);
		turret->setBulletQueued(false);
	}
	if (inputState->isKeyDown(EventKeyboard::KeyCode::KEY_SPACE))
	{
		unsigned ticks = planeModel->getTicks();
		for (size_t i = 0; i < planeModel->getNumTurrets(); i++)
		{
			Turret* turret = planeModel->getTurret(i);
			if (ticks % turret->getFireFrequency() == 0)
			{
				turret->setBulletQueued(true);
			}
		}
		planeModel->incrementTicks();

	}
	else
	{
		planeModel->resetTicks();
	}
	Controller::update(deltaTime);
}