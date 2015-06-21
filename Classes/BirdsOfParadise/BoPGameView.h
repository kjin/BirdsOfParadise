#ifndef BOP_GAME_VIEW_H_
#define BOP_GAME_VIEW_H_

#include "GameView.h"

class BoPGameView : public GameView
{
protected:
	bool init(const GameState* gameState) override;

	BoPGameView() {}
public:
	CREATE_GAME_VIEW_FUNC(BoPGameView);
};

#endif