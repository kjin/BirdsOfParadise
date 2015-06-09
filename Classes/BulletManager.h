#ifndef _BULLET_MANAGER_H_
#define _BULLET_MANAGER_H_

#include "Model.h"
#include <vector>

class Bullet;

class BulletManager : public Model
{
protected:
	std::vector<Bullet*> _bullets;
	size_t _currentIndex;
protected:
	bool init(size_t numBullets);
	~BulletManager();
public:
	static BulletManager* create(size_t numBullets)
	{
		BulletManager* bulletManager = new BulletManager();
		if (bulletManager && bulletManager->init(numBullets))
		{
			bulletManager->autorelease();
			return bulletManager;
		}
		delete bulletManager;
		return nullptr;
	}

	// Gets the next bullet with lifespan = 0. Nullptr if there is none.
	Bullet* getAvailableBullet();

	size_t getNumBullets() const { return _bullets.size(); }
	const Bullet* getBullet(size_t index) const { return _bullets[index]; }

	void update(float deltaTime) override;
};

#endif