#include "BirdsOfParadise.h"
#include "BoPBulletController.h"
#include "BoPBulletManager.h"
#include "BoPGameState.h"
#include "BoPPlaneModel.h"
#include "BoPTurret.h"
#include "BoPBullet.h"

using namespace cocos2d;

void BulletController::update(float deltaTime)
{
	BulletManager* bulletManager = (BulletManager*)_model;

	const PlaneModel* playerModel = (const PlaneModel*)_gameState->getModel(VID_SINGLETON, IID_PLAYER);
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
