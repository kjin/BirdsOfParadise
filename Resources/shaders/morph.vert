#define MAX_POINTS 2000
#define INSTANCE_POINTS 36

attribute vec3 a_position;
attribute vec2 a_texCoord;

uniform vec3 u_positions[MAX_POINTS];
uniform vec2 u_texCoords[MAX_POINTS];
uniform vec3 u_instanceVertexPositions[INSTANCE_POINTS];

varying vec2 v_texCoord;
varying vec4 v_normal;

void main()
{
    int instanceID = int(a_texCoord.x);
    int vertexID = int(a_texCoord.y);
    v_normal = vec4(0, 0, 1, 1);
    v_texCoord = u_texCoords[instanceID];
    v_texCoord.y = 1 - v_texCoord.y;
    vec4 position = vec4(u_positions[instanceID] + u_instanceVertexPositions[vertexID], 1);
    gl_Position = CC_MVPMatrix * position;
}
