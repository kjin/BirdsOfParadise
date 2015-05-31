#ifndef _BOP_PLAYER_MODEL_H_
#define _BOP_PLAYER_MODEL_H_

#include "SegmentedSprite3DModel.h"

class PlayerModel : public SegmentedSprite3DModel
{
public:
	static PlayerModel* create();
};

#endif