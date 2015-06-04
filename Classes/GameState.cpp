#include "GameState.h"
#include "InputState.h"
#include "cocos2d.h"
#include "Model.h"

using namespace cocos2d;

GameState::GameState()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	_inputState = new InputState();

	_playerModel = Model::create();
	_playerModel->retain();
	_playerModel->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	_playerModel->setModelDampeningFactor(0.8);
}

GameState::~GameState()
{
	delete _inputState;
	_playerModel->release();
}

void GameState::update(float deltaTime)
{
	_playerModel->updateModel(deltaTime);
}
