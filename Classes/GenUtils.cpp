#include "GenUtils.h"
#include "OBJ.h"
#include <vector>

using namespace cocos2d;
using namespace std;

Mesh* GenUtils::OBJToCocos2dMesh(const OBJ& obj)
{
	OBJ::VertexDeclaration vertexDeclaration = obj.getVertexDeclaration();
	size_t perVertexSize = OBJ::getVertexSizeInBytes(vertexDeclaration) / sizeof(float);

	const vector<OBJ::Vertex>& objVertices = obj.getVertices();
	vector<float> vertices;
	for (unsigned i = 0; i < objVertices.size(); i++)
	{
		if (vertexDeclaration & OBJ::Position)
		{
			vertices.push_back(objVertices[i].vx);
			vertices.push_back(objVertices[i].vy);
			vertices.push_back(objVertices[i].vz);
		}
#if VERTEX_HAS_TEXTURE
		if (vertexDeclaration & OBJ::Texture)
		{
			vertices.push_back(objVertices[i].vtx);
			vertices.push_back(objVertices[i].vty);
		}
#endif
#if VERTEX_HAS_NORMAL
		if (vertexDeclaration & OBJ::Normal)
		{
			vertices.push_back(objVertices[i].vnx);
			vertices.push_back(objVertices[i].vny);
			vertices.push_back(objVertices[i].vnz);
		}
#endif
	}

	const vector<OBJ::Triangle>& objTriangles = obj.getTriangles();
	Mesh::IndexArray indices;
	for (unsigned i = 0; i < objTriangles.size(); i++)
	{
		indices.push_back(objTriangles[i].v1);
		indices.push_back(objTriangles[i].v2);
		indices.push_back(objTriangles[i].v3);
	}

	// Vertex Attributes
	vector<MeshVertexAttrib> attributes;
	MeshVertexAttrib attribute;
	attribute.type = GL_FLOAT; // it's always this
	if (vertexDeclaration & OBJ::Position)
	{
		attribute.vertexAttrib = GLProgram::VERTEX_ATTRIB_POSITION;
		attribute.size = 3;
		attribute.attribSizeBytes = attribute.size * sizeof(float);
		attributes.push_back(attribute);
	}
	if (vertexDeclaration & OBJ::Texture)
	{
		attribute.vertexAttrib = GLProgram::VERTEX_ATTRIB_TEX_COORD;
		attribute.size = 2;
		attribute.attribSizeBytes = attribute.size * sizeof(float);
		attributes.push_back(attribute);
	}
	if (vertexDeclaration & OBJ::Normal)
	{
		attribute.vertexAttrib = GLProgram::VERTEX_ATTRIB_NORMAL;
		attribute.size = 3;
		attribute.attribSizeBytes = attribute.size * sizeof(float);
		attributes.push_back(attribute);
	}

	auto mesh = Mesh::create(vertices, perVertexSize, indices, attributes);
	//mesh->autorelease();
	return mesh;
}
