#include "GameController.h"
#include <vector>
#include "GameState.h"
#include "InputState.h"
#include "InputController.h"
#include "Controller.h"

using namespace std;
USING_NS_CC;

// on "init" you need to initialize your instance
bool GameController::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	scheduleUpdate();
	_gameState = nullptr;
	_inputController = nullptr;
    return true;
}

void GameController::update(float deltaTime)
{
	if (_gameState != nullptr && _inputController == nullptr)
	{
		_inputController = InputController::create(_gameState->getInputState(), _eventDispatcher);
		_inputController->retain();
	}
	for (Controller* controller : _modelControllers)
	{
		controller->update(deltaTime);
	}
}

void GameController::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
