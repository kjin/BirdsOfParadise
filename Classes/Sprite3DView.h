#ifndef _BOP_SPRITE_3D_MODEL_H_
#define _BOP_SPRITE_3D_MODEL_H_

#include "cocos2d.h"
#include <string>

class OBJ;
class Model;

class Sprite3DView : public cocos2d::Sprite3D
{
protected:
	const Model* _model;
protected:
	bool initWithModel(const Model* model);

	virtual bool initWithModelAndFile(const Model* model, const std::string& modelPath);

	bool init() override;

	void update(float deltaTime) override;
public:
	static Sprite3DView* createWithModelAndFile(const Model* model, const std::string& modelPath);
};

#endif