#ifndef BOP_GAME_CONTROLLER_H_
#define BOP_GAME_CONTROLLER_H_

#include "GameController.h"

class BoPGameController : public GameController
{
	bool init() override;
public:
	CREATE_FUNC(BoPGameController);
};

#endif