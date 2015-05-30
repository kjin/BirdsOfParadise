#ifndef _BOP_SPRITE_3D_MODEL_H_
#define _BOP_SPRITE_3D_MODEL_H_

#include "cocos2d.h"
#include "Model.h"

class Sprite3DModel : public cocos2d::Sprite3D, public Model
{
public:
	static Sprite3DModel* createFromFile(const char* fileName);

	bool init() override;
};

#endif