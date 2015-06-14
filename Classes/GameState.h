#ifndef _BOP_GAME_STATE_H_
#define _BOP_GAME_STATE_H_

#include "cocos2d.h"
#include "Array2D.h"

class InputState;
class GameController;
class Model;
class PlaneModel;
class BulletManager;

#define GAMESTATE_MODEL(_modelType, _modelName, _getterName) private: _modelType* _modelName; public: _modelType* _getterName() { return _modelName; } _modelType* _getterName() const { return _modelName; }

class GameState : public cocos2d::Ref
{
	friend class GameController;
protected:
	InputState* _inputState;
	Array2D<Model*>* _models;
protected:
	bool init(unsigned numRows);

	~GameState();
public:
	InputState* getInputState() { return _inputState; }
	const InputState* getInputState() const { return _inputState; }

	GAMESTATE_MODEL(PlaneModel, _playerModel, getPlayerModel);
	GAMESTATE_MODEL(BulletManager, _bulletManager, getBulletManager);
};

#endif