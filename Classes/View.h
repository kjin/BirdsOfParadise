// View.h
// 6/20/2015

#ifndef VIEW_H_
#define VIEW_H_

#include "cocos2d.h"

class Model;

class View : public cocos2d::Ref
{
protected:
	const Model* _model;
	cocos2d::Node* _sceneGraphNode;

	~View();
public:
	bool init(const Model* model, cocos2d::Node* node);

	static View* create(const Model* model, cocos2d::Node* node);

	static View* create()
	{
		return create(nullptr, nullptr);
	}

	cocos2d::Node* getNode() { return _sceneGraphNode; }

	virtual void update(float deltaTime);
};

#endif