#include "PlaneModel.h"
#include "Turret.h"

using namespace cocos2d;

PlaneModel::~PlaneModel()
{
	for (size_t i = 0; i < _turrets.size(); i++)
	{
		_turrets[i]->release();
		_turrets[i] = nullptr;
	}
}

void PlaneModel::addTurret(const Vec3& position, const Vec3& direction, const BulletDefinition& bulletDefinition)
{
	Turret* turret = Turret::create();
	turret->retain();
	turret->setPosition(position);
	turret->setDirection(direction);
	turret->setBulletDefinition(bulletDefinition);
	_turrets.push_back(turret);
}
