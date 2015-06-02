#include "GameController.h"
#include <vector>
#include "OBJ.h"
#include "GenUtils.h"
#include "PlayerModel.h"
#include "GameState.h"
#include "InputState.h"
#include "InputController.h"
#include "PlayerController.h"

using namespace std;
USING_NS_CC;

Scene* GameController::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameController::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameController::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Director::getInstance()->getRenderer()->setClearColor(Color4F::WHITE);

	_label = Label::create();
	_label->setColor(Color3B::BLACK);
	_label->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 50);
	_label->setString("This is a test.");
	addChild(_label);

	// Add input to the story
	_gameState = new GameState();
	_inputController = InputController::create(_gameState->_inputState, _eventDispatcher);
	_inputController->retain();

	// Player model //
	auto plane = PlayerModel::create();
	plane->setColor(Color3B::RED);
	plane->setScale(2);
	plane->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	plane->runAction(RotateBy::create(100, Vec3(3600, 0, 0)));
	plane->setModelDampeningFactor(0.8);
	addChild(plane);
	// Control our dear player
	_playerController = PlayerController::create(_gameState, plane);

	scheduleUpdate();
    
    return true;
}

void GameController::update(float deltaTime)
{
	// whoop de doo
	_label->setString(_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_SPACE) ? "down" : "up");
	_playerController->update(deltaTime);
}

void GameController::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
