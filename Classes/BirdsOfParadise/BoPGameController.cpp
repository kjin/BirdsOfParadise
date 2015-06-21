#include "cocos2d.h"
#include "BirdsOfParadise.h"
#include "BoPGameController.h"
#include "BoPGameState.h"
#include "BoPGameView.h"
#include "BoPPlayerController.h"
#include "BoPBulletManager.h"
#include "BoPBulletController.h"
#include "BoPPlaneModel.h"

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
	auto gameState = BoPGameState::create();
	setGameState(gameState);

	// View
	auto gameView = BoPGameView::create(gameState);
	setGameView(gameView);

	// Controller
	auto playerModel = (PlaneModel*)gameState->getModel(VID_SINGLETON, IID_PLAYER);
	auto bulletManager = (BulletManager*)gameState->getModel(VID_SINGLETON, IID_BULLET_MANAGER);

	addController(PlayerController::create(gameState, (Model*)playerModel));
	addController(BulletController::create(gameState, (Model*)bulletManager));
	return true;
}
