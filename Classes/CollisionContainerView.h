#ifndef _COLLISION_VIEW_H_
#define _COLLISION_VIEW_H_

#include "Sprite3DView.h"
#include <string>

class Model;

class CollisionContainerView : public Sprite3DView
{
public:
	static CollisionContainerView* createWithModel(const Model* model);

	void update(float deltaTime) override;
};

#endif