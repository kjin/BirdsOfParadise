#include "GameController.h"
#include <vector>
#include "OBJ.h"
#include "GenUtils.h"
#include "PlayerView.h"
#include "CollisionContainer.h"
#include "CollisionContainerView.h"
#include "GameState.h"
#include "InputState.h"
#include "InputController.h"
#include "PlayerController.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "BulletController.h"

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

	// Model
	_gameState = new GameState();
	_inputController = InputController::create(_gameState->getInputState(), _eventDispatcher);
	_inputController->retain();

	// View
	auto playerView = PlayerView::createWithModel((Model*)_gameState->getPlayerModel());
	playerView->setColor(Color3B::RED);
	playerView->setScale(2);
	addChild(playerView);
	auto playerCollisionView = CollisionContainerView::createWithModel((Model*)_gameState->getPlayerModel());
	addChild(playerCollisionView);

	// Camera

	auto glProgram = GLProgram::createWithFilenames("shaders/myShader.vert", "shaders/myShader.frag");

	const BulletManager* bulletManager = _gameState->getBulletManager();
	for (unsigned i = 0; i < bulletManager->getNumBullets(); i++)
	{
		auto bulletView = Sprite3DView::createWithModelAndFile((Model*)bulletManager->getBullet(i), "models/unitSphere.obj");
		bulletView->setGLProgram(glProgram);
		bulletView->setScale(10);
		addChild(bulletView);
	}

	// Controller
	auto playerController = PlayerController::create(_gameState, (Model*)_gameState->getPlayerModel());
	playerController->retain();
	_modelControllers.push_back(playerController);
	auto bulletController = BulletController::create(_gameState, (Model*)_gameState->getBulletManager());
	bulletController->retain();
	_modelControllers.push_back(bulletController);

	scheduleUpdate();
    
    return true;
}

void GameController::update(float deltaTime)
{
	// whoop de doo
	_label->setString(_gameState->getInputState()->isKeyDown(EventKeyboard::KeyCode::KEY_SPACE) ? "down" : "up");
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
