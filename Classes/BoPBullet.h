#ifndef _BULLET_MODEL_H_
#define _BULLET_MODEL_H_

#include "cocos2d.h"
#include "Model.h"

class Bullet : public Model
{
protected:
	unsigned _lifespan;

	Bullet() : _lifespan(0) {}

	void updateHealth()
	{
		if (_lifespan > 0)
		{
			_modelHealth = 1;
		}
		else
		{
			_modelHealth = 0;
		}
	}
public:
	CREATE_FUNC(Bullet);

	unsigned getLifespan() const { return _lifespan; }
	void setLifespan(unsigned lifespan) { _lifespan = lifespan; updateHealth(); }
	void decrementLifespan() { _lifespan--; updateHealth(); }
};

#endif