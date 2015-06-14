#include "GameState.h"
#include "InputState.h"
#include "cocos2d.h"
#include "PlaneModel.h"
#include "BulletManager.h"
#include "Definitions.h"

using namespace cocos2d;

bool GameState::init(unsigned numRows)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	_inputState = new InputState();

	_models = new Array2D<Model*>();
	_models->addNumRows(numRows);

	BulletDefinition playerBulletDefinition;
	playerBulletDefinition.initialVelocity = 10.0f;
	playerBulletDefinition.lifespan = 100;

	_playerModel = PlaneModel::create();
	_playerModel->retain();
	_playerModel->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	_playerModel->setModelDampeningFactor(0.8f);
	_playerModel->addTurret(Vec3::ZERO, Vec3::UNIT_Y, playerBulletDefinition);
	_playerModel->setCollisionRadius(25.0f);

	_bulletManager = BulletManager::create(50);
	_bulletManager->retain();
	return true;
}

GameState::~GameState()
{
	delete _inputState;
	delete _models;
	_playerModel->release();
	_bulletManager->release();
}
