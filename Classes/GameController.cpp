#include "GameController.h"
#include <vector>
#include "OBJ.h"
#include "GenUtils.h"
#include "PlayerModel.h"

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

	auto plane = PlayerModel::create();
	plane->setColor(Color3B::RED);
	plane->setModelPosition(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	addChild(plane);
    
    return true;
}


void GameController::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
