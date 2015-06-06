#define MAX_POINTS 960
#define INSTANCE_TRIANGLES 12
#define INSTANCE_POINTS 3 * INSTANCE_TRIANGLES

attribute vec3 a_position;
attribute vec2 a_texCoord;

uniform vec3 u_positions[MAX_POINTS];
uniform vec3 u_instanceVertexPositions[INSTANCE_POINTS];

varying vec2 v_texCoord;
varying vec4 v_normal;

void main()
{
    int instanceID = int(a_position.x);
    int vertexID = int(a_position.y);
    float t = (sin(CC_Time.w) + 1.0) / 2.0;
    v_normal = vec4(0, 0, 1, 1);
    v_texCoord = a_texCoord;
    vec4 position = vec4(u_positions[instanceID] * (1.0 + 5.0 * t) + u_instanceVertexPositions[vertexID], 1);
    gl_Position = CC_MVPMatrix * position;
}
