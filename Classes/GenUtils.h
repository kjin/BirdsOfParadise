#ifndef _GEN_UTILS_H_
#define _GEN_UTILS_H_

#include "cocos2d.h"
#include <vector>

class OBJ;

class GenUtils
{
public:
	static cocos2d::Mesh* OBJToCocos2dMesh(const OBJ& obj);

	static cocos2d::Mesh* CreateGeometryInstancedMesh(int numInstances, int verticesPerInstance, const std::vector<int>& instanceTriangulation);
};

#endif
