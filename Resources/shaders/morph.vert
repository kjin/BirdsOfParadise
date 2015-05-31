attribute vec3 a_position;
attribute vec2 a_texCoord;

uniform vec3 u_positions[2000];
uniform vec2 u_texCoords[2000];

varying vec2 v_texCoord;
varying vec4 v_normal;

void main()
{
    int instanceID = int(a_texCoord.x);
    int vertexID = int(a_texCoord.y);
    v_normal = vec4(0, 0, 1, 1);
    v_texCoord = u_texCoords[instanceID];
    v_texCoord.y = 1 - v_texCoord.y;
    
    vec4 position = vec4(u_positions[instanceID], 1);
    if (vertexID == 0)
    {
        position.xy += vec2(-0.5, -0.5);
    }
    if (vertexID == 1)
    {
        position.xy += vec2(0.5, -0.5);
    }
    if (vertexID == 2)
    {
        position.xy += vec2(0.5, 0.5);
    }
    if (vertexID == 3)
    {
        position.xy += vec2(-0.5, 0.5);
    }
    gl_Position = CC_MVPMatrix * position;
}
