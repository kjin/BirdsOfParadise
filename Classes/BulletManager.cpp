#include "BulletManager.h"
#include "Bullet.h"

bool BulletManager::init(size_t numBullets)
{
	for (size_t i = 0; i < numBullets; i++)
	{
		_bullets.push_back(Bullet::create());
		_bullets[i]->retain();
	}
	_currentIndex = 0;
	return true;
}

BulletManager::~BulletManager()
{
	for (size_t i = 0; i < _bullets.size(); i++)
	{
		_bullets[i]->release();
		_bullets[i] = nullptr;
	}
}

Bullet* BulletManager::getAvailableBullet()
{
	Bullet* result = nullptr;
	if (_bullets[_currentIndex]->getLifespan() == 0)
	{
		result = _bullets[_currentIndex];
		_currentIndex++;
		if (_currentIndex == _bullets.size())
		{
			_currentIndex = 0;
		}
	}
	return result;
}

void BulletManager::update(float deltaTime)
{
	for (Bullet* bullet : _bullets)
	{
		if (bullet->getLifespan() > 0)
		{
			bullet->update(deltaTime);
			bullet->decrementLifespan();
		}
	}
}
