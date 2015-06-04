#ifndef _BOP_SPRITE_3D_MODEL_H_
#define _BOP_SPRITE_3D_MODEL_H_

#include "cocos2d.h"
#include "Model.h"

class OBJ;

class Sprite3DView : public cocos2d::Sprite3D
{
protected:
	const Model* _model;
protected:
	bool initWithModel(const Model* model);

	bool init() override;

	void update(float deltaTime) override;
};

#endif