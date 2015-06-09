#include "BulletController.h"
#include "BulletManager.h"
#include "GameState.h"
#include "PlaneModel.h"
#include "Turret.h"
#include "Bullet.h"

using namespace cocos2d;

void BulletController::update(float deltaTime)
{
	BulletManager* bulletManager = (BulletManager*)_model;

	const PlaneModel* playerModel = _gameState->getPlayerModel();
	for (size_t i = 0; i < playerModel->getNumTurrets(); i++)
	{
		const Turret* turret = playerModel->getTurret(i);
		if (turret->getBulletQueued())
		{
			Bullet* bullet = bulletManager->getAvailableBullet();
			if (bullet != nullptr)
			{
				bullet->setModelPosition(playerModel->getModelPosition() + turret->getPosition());
				bullet->setModelVelocity(turret->getDirection() * turret->getBulletDefinition().initialVelocity);
				bullet->setLifespan(turret->getBulletDefinition().lifespan);
			}
		}
	}

	Controller::update(deltaTime);
}
