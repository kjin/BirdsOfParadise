#include "Model.h"
#include "Team.h"

bool Model::init()
{
	_modelPosition = cocos2d::Vec3(0, 0, 0);
	_modelVelocity = cocos2d::Vec3(0, 0, 0);
	_modelDampeningFactor = 1;
	_modelHealth = 1;
	_modelTeam = Team::NEUTRAL;
	return true;
}