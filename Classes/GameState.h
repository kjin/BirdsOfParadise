#ifndef _BOP_GAME_STATE_H_
#define _BOP_GAME_STATE_H_

class InputState;
class GameController;

class GameState
{
	friend class GameController;
private:
	InputState* _inputState;
public:
	GameState();

	~GameState();

	const InputState* getInputState() const { return _inputState; }
};

#endif