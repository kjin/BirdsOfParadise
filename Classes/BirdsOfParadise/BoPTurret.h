#ifndef _TURRET_H_
#define _TURRET_H_

#include "cocos2d.h"
#include "BoPDefinitions.h"

// Defines a class that shoots bullets.
class Turret : public cocos2d::Ref
{
protected:
	bool init()
	{
		_fireFrequency = 5; //TODO make this not a magic number.
		_bulletQueued = false;
		return true;
	}

	cocos2d::Vec3 _position;
	cocos2d::Vec3 _direction;
	unsigned _fireFrequency;
	BulletDefinition _bulletDefinition;

	bool _bulletQueued;
public:

	CREATE_FUNC(Turret);

	// Gets the turret's position.
	cocos2d::Vec3 getPosition() const { return _position; }
	// Sets the turret's position.
	void setPosition(cocos2d::Vec3 position) { _position = position; }

	// Gets the turret's direction.
	cocos2d::Vec3 getDirection() const { return _direction; }
	// Sets the turret's direction.
	void setDirection(cocos2d::Vec3 direction) { _direction = direction; }

	// Gets the turret's bullet definition.
	BulletDefinition getBulletDefinition() const { return _bulletDefinition; }
	// Sets the turret's bullet definition.
	void setBulletDefinition(const BulletDefinition& bulletDefinition) { _bulletDefinition = bulletDefinition; }

	// Gets the turret's fire frequency.
	unsigned getFireFrequency() const { return _fireFrequency; }
	// Sets the turret's fire frequency.
	void setFireFrequency(unsigned fireFrequency) { _fireFrequency = fireFrequency; }

	// Gets whether a bullet is queued in the turret.
	bool getBulletQueued() const { return _bulletQueued; }
	// Sets whether a bullet is queued in the turret.
	void setBulletQueued(bool bulletQueued) { _bulletQueued = bulletQueued; }
};

#endif
