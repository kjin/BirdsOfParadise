#ifndef BOP_GAME_STATE_H_
#define BOP_GAME_STATE_H_

#include "GameState.h"

class BoPGameState : public GameState
{
protected:
	bool init() override;

	BoPGameState() {}
public:
	GAME_STATE_CREATE_FUNC(BoPGameState);
};

#endif