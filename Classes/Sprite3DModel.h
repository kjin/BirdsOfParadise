#ifndef _BOP_SPRITE_3D_MODEL_H_
#define _BOP_SPRITE_3D_MODEL_H_

#include "cocos2d.h"
#include "Model.h"

class OBJ;

class Sprite3DModel : public cocos2d::Sprite3D, public Model
{
protected:
	// delete[] these!
	cocos2d::Vec3* _positions;
	cocos2d::Vec2* _texCoords;
public:
	static Sprite3DModel* createFromFile(const char* fileName);
protected:
	Sprite3DModel() {}
};

#endif