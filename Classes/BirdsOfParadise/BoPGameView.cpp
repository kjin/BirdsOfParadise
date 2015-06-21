#include "OBJ.h"
#include "GenUtils.h"
#include "GLProgramManager.h"
#include "GameState.h"
#include "BirdsOfParadise.h"
#include "BoPGameView.h"
#include "Model.h"
#include "BoPPlaneModel.h"
#include "BoPBulletManager.h"
#include "BoPPlaneView.h"
#include "CollisionContainerView.h"
#include "GenUtils.h"

using namespace cocos2d;

bool BoPGameView::init(const GameState* gameState)
{
	if (!GameView::init(gameState))
	{
		return false;
	}
	auto playerModel = (PlaneModel*)gameState->getModel(VID_SINGLETON, IID_PLAYER);
	auto bulletManager = (BulletManager*)gameState->getModel(VID_SINGLETON, IID_BULLET_MANAGER);

	auto playerView = PlaneView::createWithModel((Model*)playerModel);
	playerView->getNode()->setColor(Color3B::BLUE);
	playerView->getNode()->setScale(2);
	addView(playerView);
	auto playerCollisionView = CollisionContainerView::createWithModel((Model*)playerModel);
	addView(playerCollisionView);

	/*auto camera = Camera::createPerspective(45, 1.0f, 0.1f, 1000.0f);
	camera->setPosition3D(playerModel->getModelPosition() + Vec3(-100, -100, 100));
	camera->lookAt(playerModel->getModelPosition());
	addChild(camera);
	camera->setCameraFlag(CameraFlag::USER1);
	setCameraMask(2);*/

	auto cube = Sprite3D::create("models/halfUnitCube.obj");
	OBJ* obj = GenUtils::Cocos2dMeshToOBJ(cube->getMesh());
	auto glProgram = GLProgramManager::getInstance()->getProgram("colorByNormals");
	auto texture = Director::getInstance()->getTextureCache()->addImage("textures/bullet.png");
	for (unsigned i = 0; i < bulletManager->getNumBullets(); i++)
	{
		auto bulletView = Sprite3DView::createWithModelAndFile((Model*)bulletManager->getBullet(i), "models/unitSphere.obj");
		//auto bulletView = SegmentedSprite3DView::create((Model*)bulletManager->getBullet(i), "data/bullet.txt", obj, texture);
		//auto bulletView = BulletView::createWithModel((Model*)bulletManager->getBullet(i));
		bulletView->getNode()->setGLProgram(glProgram);
		bulletView->getNode()->setColor(Color3B::GREEN);
		bulletView->getNode()->setScale(2);
		addView(bulletView);
	}
	return true;
}
