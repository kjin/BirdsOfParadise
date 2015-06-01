#include "GameState.h"
#include "InputState.h"

GameState::GameState()
{
	_inputState = new InputState();
}

GameState::~GameState()
{
	delete _inputState;
}
