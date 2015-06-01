#ifndef _PLAYER_CONTROLLER_H_
#define _PLAYER_CONTROLLER_H_

#include "Controller.h"

class PlayerController : public Controller
{
public:
	CONTROLLER_CREATE_FUNC(PlayerController);

	void update(float deltaTime) override;
};

#endif