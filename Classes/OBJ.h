#ifndef _OBJ_H_
#define _OBJ_H_

#include <vector>
#include <ostream>
#include "cocos2d.h"

#define VERTEX_HAS_TEXTURE 1
#define VERTEX_HAS_NORMAL 1

#define REAL float

#define QUAD_HELPER(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4) addQuad(v1.set_position(x1, y1, z1).set_texture(vtx, vty), v2.set_position(x2, y2, z2).set_texture(vtx, vty), v3.set_position(x3, y3, z3).set_texture(vtx, vty), v4.set_position(x4, y4, z4).set_texture(vtx, vty));
#define CHAIN_FUNC(f, x) Vertex& f(REAL x) { this->x = x; return *this; }

class OBJ
{
public:
	typedef unsigned VertexDeclaration;
	const static VertexDeclaration Position = 1;
	const static VertexDeclaration Texture = 2;
	const static VertexDeclaration Normal = 4;

	static size_t getVertexSizeInBytes(VertexDeclaration vertexDeclaration)
	{
		size_t size = 0;
		if (vertexDeclaration & Position)
		{
			size += 3 * sizeof(REAL);
		}
		if (vertexDeclaration & Texture)
		{
			size += 2 * sizeof(REAL);
		}
		if (vertexDeclaration & Normal)
		{
			size += 3 * sizeof(REAL);
		}
		return size;
	}

    struct Vertex
    {
    public:
        // Position
        REAL vx;
        REAL vy;
        REAL vz;
        CHAIN_FUNC(set_vx, vx);
        CHAIN_FUNC(set_vy, vy);
        CHAIN_FUNC(set_vz, vz);
        Vertex& set_position(REAL vx, REAL vy, REAL vz) { this->vx = vx; this->vy = vy; this->vz = vz; return *this; }
#if VERTEX_HAS_TEXTURE
        // Texture
        REAL vtx;
        REAL vty;
        CHAIN_FUNC(set_vtx, vtx);
        CHAIN_FUNC(set_vty, vty);
        Vertex& set_texture(REAL vtx, REAL vty) { this->vtx = vtx; this->vty = vty; return *this; }
#else
        Vertex& set_texture(REAL vtx, REAL vty) { return *this; } //NOP
#endif
#if VERTEX_HAS_NORMAL
        // Normal
        REAL vnx;
        REAL vny;
        REAL vnz;
        CHAIN_FUNC(set_vnx, vnx);
        CHAIN_FUNC(set_vny, vny);
        Vertex& set_normal(REAL vnx, REAL vny, REAL vnz) { this->vnx = vnx; this->vny = vny; this->vnz = vnz; return *this; }
#else
        Vertex& set_normal(REAL vnx, REAL vny, REAL vnz) { return *this; } //NOP
#endif
    };
    
    struct Triangle
    {
    public:
        unsigned v1;
        unsigned v2;
        unsigned v3;
    };
private:
	VertexDeclaration _vertexDeclaration;
	std::vector<Vertex> _vertices;
	std::vector<Triangle> _triangles;
public:
	OBJ()
		: _vertexDeclaration(Position) {}

	OBJ(VertexDeclaration vertexDeclaration)
		: _vertexDeclaration(vertexDeclaration | Position) // We gotta have position
	{
#if !VERTEX_HAS_TEXTURE
		_vertexDeclaration &= ~Texture;
#endif
#if !VERTEX_HAS_NORMAL
		_vertexDeclaration &= ~Normal;
#endif
	}

	VertexDeclaration getVertexDeclaration() const { return _vertexDeclaration; }

	const std::vector<Vertex>& getVertices() const { return _vertices; }

	const std::vector<Triangle>& getTriangles() const { return _triangles; }

	void addTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3)
	{
		// Calculate normals.
		// The results will be ignored if !VERTEX_HAS_NORMAL
		cocos2d::Vec3 vec1(v1.vx, v1.vy, v1.vz);
		cocos2d::Vec3 vec2(v2.vx, v2.vy, v2.vz);
		cocos2d::Vec3 vec3(v3.vx, v3.vy, v3.vz);
		cocos2d::Vec3 normal(vec2 - vec1);
		normal.cross(vec3 - vec1);
		normal.normalize();

		Triangle t;
		t.v1 = _vertices.size();
		_vertices.push_back(v1);
		_vertices[t.v1].set_normal(normal.x, normal.y, normal.z);
		t.v2 = _vertices.size();
		_vertices.push_back(v2);
		_vertices[t.v2].set_normal(normal.x, normal.y, normal.z);
		t.v3 = _vertices.size();
		_vertices.push_back(v3);
		_vertices[t.v3].set_normal(normal.x, normal.y, normal.z);
		_triangles.push_back(t);
	}

	// Add quad where v1, v2, v3, and v4 are either cw or ccw.
	void addQuad(const Vertex& v1, const Vertex& v2, const Vertex& v3, const Vertex v4)
	{
		addTriangle(v1, v2, v3);
		addTriangle(v1, v3, v4);
	}

	// Add box size (sx, sy, sz) centered at (x, y, z) with a single texcoord.
	void addAABB(REAL x, REAL y, REAL z, REAL sx, REAL sy, REAL sz, REAL vtx, REAL vty)
	{
		Vertex v1, v2, v3, v4;
		float x1 = x - sx / 2;
		float x2 = x + sx / 2;
		float y1 = y - sy / 2;
		float y2 = y + sy / 2;
		float z1 = z - sz / 2;
		float z2 = z + sz / 2;
		QUAD_HELPER(x1, y1, z1, x1, y2, z1, x2, y2, z1, x2, y1, z1);
		QUAD_HELPER(x1, y1, z2, x2, y1, z2, x2, y2, z2, x1, y2, z2);
		QUAD_HELPER(x1, y1, z1, x2, y1, z1, x2, y1, z2, x1, y1, z2);
		QUAD_HELPER(x1, y2, z1, x1, y2, z2, x2, y2, z2, x2, y2, z1);
		QUAD_HELPER(x1, y1, z1, x1, y1, z2, x1, y2, z2, x1, y2, z1);
		QUAD_HELPER(x2, y1, z1, x2, y2, z1, x2, y2, z2, x2, y1, z2);
	}

	// Add box size (sx, sy, sz) centered at (x, y, z).
	void addAABB(REAL x, REAL y, REAL z, REAL sx, REAL sy, REAL sz)
	{
		addAABB(x, y, z, sx, sy, sz, 0, 0);
	}

	void print(std::ostream& ostr)
	{
		if (_vertexDeclaration & Position) // Always true, but for the sake of consistency
		{
			for (size_t i = 0; i < _vertices.size(); i++)
			{
				ostr << "v " << _vertices[i].vx << " " << _vertices[i].vy << " " << _vertices[i].vz << std::endl;
			}
		}
#if VERTEX_HAS_TEXTURE
		if (_vertexDeclaration & Texture)
		{
			for (size_t i = 0; i < _vertices.size(); i++)
			{
				ostr << "vt " << _vertices[i].vtx << " " << _vertices[i].vty << std::endl;
			}
		}
#endif
#if VERTEX_HAS_NORMAL
		if (_vertexDeclaration & Normal)
		{
			for (size_t i = 0; i < _vertices.size(); i++)
			{
				ostr << "vn " << _vertices[i].vnx << " " << _vertices[i].vny << " " << _vertices[i].vnz << std::endl;
			}
		}
#endif
		for (size_t i = 0; i < _triangles.size(); i++)
		{
#if VERTEX_HAS_TEXTURE && VERTEX_HAS_NORMAL
			// Position, normal + texture
			if (!(_vertexDeclaration & ~(Position | Texture | Normal)))
			{
				ostr << "f " << (_triangles[i].v1 + 1) << "/" << (_triangles[i].v1 + 1) << "/" << (_triangles[i].v1 + 1) <<
					" " << (_triangles[i].v2 + 1) << "/" << (_triangles[i].v2 + 1) << "/" << (_triangles[i].v2 + 1) <<
					" " << (_triangles[i].v3 + 1) << "/" << (_triangles[i].v3 + 1) << "/" << (_triangles[i].v3 + 1) << std::endl;
			}
#endif
#if VERTEX_HAS_TEXTURE
			// Just position + texture
			if (!(_vertexDeclaration & ~(Position | Texture)))
			{
				ostr << "f " << (_triangles[i].v1 + 1) << "/" << (_triangles[i].v1 + 1) <<
					" " << (_triangles[i].v2 + 1) << "/" << (_triangles[i].v2 + 1) <<
					" " << (_triangles[i].v3 + 1) << "/" << (_triangles[i].v3 + 1) << std::endl;
			}
#endif
#if VERTEX_HAS_NORMAL
			// Just position + normal
			if (!(_vertexDeclaration & ~(Position | Normal)))
			{
				ostr << "f " << (_triangles[i].v1 + 1) << "//" << (_triangles[i].v1 + 1) <<
					" " << (_triangles[i].v2 + 1) << "//" << (_triangles[i].v2 + 1) <<
					" " << (_triangles[i].v3 + 1) << "//" << (_triangles[i].v3 + 1) << std::endl;
			}
#endif
			// Just position
			if (!(_vertexDeclaration & ~Position))
			{
				ostr << "f " << (_triangles[i].v1 + 1) << " " << (_triangles[i].v2 + 1) << " " << (_triangles[i].v3 + 1) << std::endl;
			}
		}
	}
};

#undef QUAD_HELPER
#undef CHAIN_FUNC

#endif