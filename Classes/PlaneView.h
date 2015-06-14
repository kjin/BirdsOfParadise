#ifndef _BOP_PLAYER_MODEL_H_
#define _BOP_PLAYER_MODEL_H_

#include "SegmentedSprite3DView.h"

class PlaneView : public SegmentedSprite3DView
{
public:
	static PlaneView* createWithModel(const Model* model);
};

#endif