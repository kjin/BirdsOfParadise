#ifndef _GEN_UTILS_H_
#define _GEN_UTILS_H_

#include "cocos2d.h"

class OBJ;

class GenUtils
{
public:
	static cocos2d::Mesh* OBJToCocos2dMesh(const OBJ& obj);
};

#endif
