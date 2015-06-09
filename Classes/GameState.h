#ifndef _BOP_GAME_STATE_H_
#define _BOP_GAME_STATE_H_

class InputState;
class GameController;
class Model;
class PlaneModel;
class BulletManager;

#define GAMESTATE_MODEL(_modelType, _modelName, _getterName) private: _modelType* _modelName; public: _modelType* _getterName() { return _modelName; } _modelType* _getterName() const { return _modelName; }

class GameState
{
	friend class GameController;
private:
	InputState* _inputState;
public:
	GameState();

	~GameState();

	InputState* getInputState() { return _inputState; }
	const InputState* getInputState() const { return _inputState; }

	GAMESTATE_MODEL(PlaneModel, _playerModel, getPlayerModel);
	GAMESTATE_MODEL(BulletManager, _bulletManager, getBulletManager);
};

#endif