#ifndef _BOP_PLAYER_MODEL_H_
#define _BOP_PLAYER_MODEL_H_

#include "SegmentedSprite3DView.h"

class PlayerView : public SegmentedSprite3DView
{
public:
	static PlayerView* createWithModel(const Model* model);
};

#endif