#ifndef _PLAYER_MODEL_H_
#define _PLAYER_MODEL_H_

#include <vector>
#include "Model.h"

class Turret;
struct BulletDefinition;

class PlaneModel : public Model
{
private:
	unsigned _ticks;
	std::vector<Turret*> _turrets;
public:
	CREATE_FUNC(PlaneModel);

	~PlaneModel();

	void addTurret(const cocos2d::Vec3& position, const cocos2d::Vec3& direction, const BulletDefinition& bulletDefinition);

	Turret* getTurret(size_t index) const { return _turrets[index]; }

	size_t getNumTurrets() const { return _turrets.size(); }

	unsigned getTicks() { return _ticks; }
	void incrementTicks() { _ticks++; }
	void resetTicks() { _ticks = 0; }
};

#endif
