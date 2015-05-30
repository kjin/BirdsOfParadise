#include "GameController.h"
#include <vector>
#include "OBJ.h"
#include "GenUtils.h"

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

	Director::getInstance()->getRenderer()->setClearColor(Color4F::BLACK);

	auto defaultGLProgram = GLProgram::createWithFilenames("shaders/myShader.vert", "shaders/myShader.frag");
	auto morphGLProgram = GLProgram::createWithFilenames("shaders/morph.vert", "shaders/morph.frag");
	
	auto defaultGLProgramState = GLProgramState::getOrCreateWithGLProgram(defaultGLProgram);
	auto morphGLProgramState = GLProgramState::getOrCreateWithGLProgram(morphGLProgram);
	morphGLProgramState->setUniformVec4("u_position", Vec4(0, 0, 0, 0));

	////////
	// Init a unit sphere.
	////////
	auto sphere = Sprite3D::create("models/unitSphere.obj");
	sphere->runAction(RotateBy::create(100.0f, Vec3(0, 100 * 360, 0)));
	sphere->setGLProgramState(defaultGLProgramState);
	sphere->setScale(100);
	sphere->setPosition3D(Vec3(visibleSize.width / 2 + 300, visibleSize.height / 2, 0));
	addChild(sphere);

	////////
	// Init something that should turn into something interesting when vertex shaders are applied.
	////////

	OBJ obj(OBJ::Position | OBJ::Texture | OBJ::Normal);
	obj.addAABB(0, 0, 0, 50, 50, 50);

	auto mesh = GenUtils::OBJToCocos2dMesh(obj);

	auto cluster = Sprite3D::create();
	cluster->addMesh(mesh);//
	cluster->setGLProgramState(morphGLProgramState);
	cluster->setPosition3D(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	cluster->runAction(RotateBy::create(100.0f, Vec3(10 * 360, 20 * 360, 0)));
	addChild(cluster);
    
    return true;
}


void GameController::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
