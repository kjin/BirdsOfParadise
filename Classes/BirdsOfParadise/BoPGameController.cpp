#include "BirdsOfParadise.h"
#include "BoPGameController.h"
#include "BoPGameState.h"
#include "cocos2d.h"
#include "OBJ.h"
#include "GenUtils.h"
#include "BoPPlaneView.h"
#include "BoPPlayerController.h"
#include "BoPBulletManager.h"
#include "BoPBullet.h"
#include "BoPBulletController.h"
#include "CollisionContainer.h"
#include "CollisionContainerView.h"

using namespace cocos2d;

bool BoPGameController::init()
{
	if (!GameController::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Director::getInstance()->getRenderer()->setClearColor(Color4F::WHITE);

	// Model
	_gameState = (GameState*)BoPGameState::create();
	_gameState->retain();
	auto playerModel = (PlaneModel*)_gameState->getModel(VID_SINGLETON, IID_PLAYER);
	auto bulletManager = (BulletManager*)_gameState->getModel(VID_SINGLETON, IID_BULLET_MANAGER);

	// View
	auto playerView = PlaneView::createWithModel((Model*)playerModel);
	playerView->setColor(Color3B::RED);
	playerView->setScale(2);
	addChild(playerView);
	auto playerCollisionView = CollisionContainerView::createWithModel((Model*)playerModel);
	addChild(playerCollisionView);

	auto glProgram = GLProgram::createWithFilenames("shaders/myShader.vert", "shaders/myShader.frag");
	for (unsigned i = 0; i < bulletManager->getNumBullets(); i++)
	{
		auto bulletView = Sprite3DView::createWithModelAndFile((Model*)bulletManager->getBullet(i), "models/unitSphere.obj");
		bulletView->setGLProgram(glProgram);
		bulletView->setScale(10);
		addChild(bulletView);
	}

	// Controller
	auto playerController = PlayerController::create(_gameState, (Model*)playerModel);
	playerController->retain();
	_modelControllers.push_back(playerController);
	auto bulletController = BulletController::create(_gameState, (Model*)bulletManager);
	bulletController->retain();
	_modelControllers.push_back(bulletController);
	return true;
}
