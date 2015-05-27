#include "GameController.h"

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

	Director::getInstance()->getRenderer()->setClearColor(Color4F::BLUE);

	auto glProgram = GLProgram::createWithFilenames("shaders/myShader.vert", "shaders/myShader.frag");

	auto glProgramState = GLProgramState::getOrCreateWithGLProgram(glProgram);

	// Init a unit sphere.
	auto sphere = Sprite3D::create("models/unitSphere.obj");
	sphere->runAction(RotateBy::create(100.0f, Vec3(0, 100 * 360, 0)));
	// For the sake of displaying things.
	/*int numVertices = sphere->getMesh()->getMeshIndexData()->getMeshVertexData()->getVertexBuffer()->getVertexNumber();
	int vertexSize = sphere->getMesh()->getMeshIndexData()->getMeshVertexData()->getVertexBuffer()->getSizePerVertex();
	auto vbo = sphere->getMesh()->getMeshIndexData()->getMeshVertexData()->getVertexBuffer()->getVBO();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	float* ptr = (float*)glMapBufferRange(GL_ARRAY_BUFFER, 0, numVertices * vertexSize, GL_MAP_READ_BIT);
	for (int i = 0; i < numVertices; i++)
	{
		CCLOG("%f %f %f %f %f %f", ptr[6 * i], ptr[6 * i + 1], ptr[6 * i + 2], ptr[6 * i + 3], ptr[6 * i + 4], ptr[6 * i + 5]);
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);*/
	sphere->setGLProgramState(glProgramState);
	sphere->setScale(100);
	sphere->setPosition3D(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0));
	addChild(sphere);
    
    return true;
}


void GameController::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
