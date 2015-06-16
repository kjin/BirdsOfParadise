#ifndef _BOP_GAME_STATE_H_
#define _BOP_GAME_STATE_H_

#include "cocos2d.h"
#include "Array2D.h"

class InputState;
class GameController;
class Model;
class PlaneModel;
class BulletManager;

class GameState : public cocos2d::Ref
{
	friend class GameController;
private:
	InputState* _inputState;
	Array2D<Model*>* _models;
protected:
	virtual bool init();

	void addModel(Model* model, unsigned vectorID, unsigned itemID);

	~GameState();
public:
	InputState* getInputState() { return _inputState; }
	const InputState* getInputState() const { return _inputState; }

	Model* getModel(unsigned vectorID, unsigned itemID) { return _models->getItem(vectorID, itemID); }
	const Model* getModel(unsigned vectorID, unsigned itemID) const { return _models->getItem(vectorID, itemID); }
};

#endif