#ifndef _BOP_GAME_STATE_H_
#define _BOP_GAME_STATE_H_

class InputState;
class GameController;
class Model;

class GameState
{
	friend class GameController;
private:
	InputState* _inputState;
	Model* _playerModel;
public:
	GameState();

	~GameState();

	InputState* getInputState() { return _inputState; }

	const InputState* getInputState() const { return _inputState; }

	Model* getPlayerModel() { return _playerModel; }

	void update(float deltaTime);
};

#endif