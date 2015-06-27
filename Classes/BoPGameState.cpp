#include "BirdsOfParadise.h"
#include "BoPPlaneModel.h"
#include "BoPBulletManager.h"
#include "BoPDefinitions.h"
#include "CameraModel.h"
#include "Model.h"

using namespace cocos2d;

bool BoPGameState::init()
{
	if (!GameState::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	BulletDefinition playerBulletDefinition;
	playerBulletDefinition.initialVelocity = 10.0f;
	playerBulletDefinition.lifespan = 100;

	auto playerModel = PlaneModel::create();
	playerModel->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	playerModel->setModelDampeningFactor(0.8f);
	playerModel->addTurret(Vec3::ZERO, Vec3::UNIT_Y, playerBulletDefinition);
	playerModel->setCollisionRadius(25.0f);
	addModel(playerModel, VID_SINGLETON, IID_PLAYER);

	auto bulletManager = BulletManager::create(50);
	addModel(bulletManager, VID_SINGLETON, IID_BULLET_MANAGER);

	auto backdrop = Model::create();
	backdrop->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, -300));
	addModel(backdrop, VID_SINGLETON, IID_BACKGROUND);

	auto cameraModel = CameraModel::create();
	addModel(cameraModel, VID_SINGLETON, IID_CAMERA);

	return true;
}