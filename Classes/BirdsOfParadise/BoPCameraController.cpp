#include "BirdsOfParadise.h"
#include "BoPCameraController.h"
#include "CameraModel.h"
#include "Model.h"
#include "BoPPlaneModel.h"
#include "GameState.h"

using namespace cocos2d;

void CameraController::update(float deltaTime)
{
	auto playerModel = (PlaneModel*)_gameState->getModel(VID_SINGLETON, IID_PLAYER);
	auto camera = (CameraModel*)_model;
	camera->setModelPosition(camera->getModelPosition().lerp(playerModel->getModelPosition() + Vec3(0, -300, 200), 0.05f));
	camera->setCameraTarget(playerModel->getModelPosition() + Vec3(0, 0, 100));
	camera->setCameraUp(Vec3::UNIT_Z);
}
