#ifndef _BOP_SEGMENTED_SPRITE_3D_MODEL_H_
#define _BOP_SEGMENTED_SPRITE_3D_MODEL_H_

#include "cocos2d.h"
#include "Sprite3DModel.h"

class OBJ;

class SegmentedSprite3DModel : public Sprite3DModel
{
protected:
	cocos2d::Vec3* _instanceVertices;
	cocos2d::Vec3* _positions;
	cocos2d::Vec2* _texCoords;
public:
	static SegmentedSprite3DModel* create(const char* inputFile, const OBJ* instanceShape, cocos2d::Texture2D* texture);
protected:
	bool init(const char* inputFile, const OBJ* instanceShape, cocos2d::Texture2D* texture);

	SegmentedSprite3DModel() {}

	~SegmentedSprite3DModel()
	{
		delete[] _instanceVertices;
		delete[] _positions;
		delete[] _texCoords;
	}
public:
	void update(float deltaTime) override;
};

#endif