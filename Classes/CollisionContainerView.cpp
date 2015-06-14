#include "CollisionContainerView.h"
#include "CollisionContainer.h"
#include "Model.h"
#include "cocos2d.h"

using namespace cocos2d;

bool CollisionContainerView::initWithModelAndFile(const Model* model, const std::string& modelPath)
{
	if (Sprite3DView::initWithModelAndFile(model, modelPath))
	{
		auto glProgram = GLProgram::createWithFilenames("shaders/collisionContainer.vert", "shaders/collisionContainer.frag");
		this->setGLProgramState(GLProgramState::getOrCreateWithGLProgram(glProgram));
		this->setColor(Color3B::YELLOW);
		return true;
	}
	return false;
}

CollisionContainerView* CollisionContainerView::createWithModel(const Model* model)
{
	CollisionContainerView* pRet = new CollisionContainerView();
	if (pRet && pRet->initWithModelAndFile(model, "models/unitSphere.obj"))
	{
		pRet->autorelease();
		return pRet;
	}
	delete pRet;
	return nullptr;
}

void CollisionContainerView::update(float deltaTime)
{
	if (_model->getModelHealth() > 0 && _model->getCollisionContainer() != nullptr)
	{
		setVisible(true);
		setPosition3D(_model->getCollisionContainer()->getPosition());
		setScale(((SphericalCollisionContainer*)_model->getCollisionContainer())->getRadius());
	}
	else
	{
		setVisible(false);
	}
}
