#ifndef _BOP_GAME_CONTROLLER_H_
#define _BOP_GAME_CONTROLLER_H_

#include "cocos2d.h"

class GameState;
class InputController;
class Controller;

class GameController : public cocos2d::Layer
{
public:
	// This is temporary
	cocos2d::Label* _label;

	// State
	GameState* _gameState;

	// Controller
	InputController* _inputController;
	std::vector<Controller*> _modelControllers;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

	void update(float deltaTime) override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameController);
};

#endif // __HELLOWORLD_SCENE_H__
