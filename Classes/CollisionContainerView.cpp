#include "CollisionContainerView.h"
#include "CollisionContainer.h"
#include "Model.h"

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
