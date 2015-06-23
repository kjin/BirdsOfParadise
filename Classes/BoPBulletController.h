#ifndef _BULLET_CONTROLLER_H_
#define _BULLET_CONTROLLER_H_

#include "Controller.h"

class BulletController : public Controller
{
public:
	CONTROLLER_CREATE_FUNC(BulletController);

	void update(float deltaTime) override;
};

#endif