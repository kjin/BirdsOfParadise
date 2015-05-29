#include "GameController.h"
#include <vector>

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

	Director::getInstance()->getRenderer()->setClearColor(Color4F::BLUE);

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

	// Vertices.
	vector<float> vertices;
	// Indices.
	Mesh::IndexArray indices;
	for (int i = 0; i < 300; i++)
	{
#define RAND_FLOAT (rand() % 100 / 100.0f)
		Vec3 v(RAND_FLOAT, RAND_FLOAT, RAND_FLOAT);
		v.scale((RAND_FLOAT - 0.5f));
		vertices.push_back(v.x);
		vertices.push_back(v.y);
		vertices.push_back(v.z);
		vertices.push_back(RAND_FLOAT + 0.5f);
		indices.push_back(i);
	}
	
	// Vertex Attributes
	vector<MeshVertexAttrib> attributes;
	MeshVertexAttrib attribute;
	attribute.vertexAttrib = GLProgram::VERTEX_ATTRIB_POSITION;
	attribute.size = 4;
	attribute.attribSizeBytes = attribute.size * sizeof(float);
	attribute.type = GL_FLOAT;
	attributes.push_back(attribute);

	auto mesh = Mesh::create(vertices, 4, indices, attributes);

	auto cluster = Sprite3D::create();
	cluster->addMesh(mesh);
	cluster->setGLProgramState(morphGLProgramState);
	cluster->setScale(100);
	cluster->setPosition3D(Vec3(visibleSize.width / 2, visibleSize.height / 2, 0)); //
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
