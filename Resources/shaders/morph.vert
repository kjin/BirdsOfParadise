// Actually used as direction
attribute vec3 a_position;
attribute vec2 a_texCoord;
attribute vec3 a_normal;

uniform vec4 u_position;

varying vec2 v_texCoord;
varying vec4 v_normal;

void main()
{
    v_normal = vec4(a_normal, 0);
    v_texCoord = vec2(1 - a_texCoord.x, a_texCoord.y);
    //gl_Position = CC_MVPMatrix * vec4((2.0 + sin(CC_Time.w)) * a_position, 1);
    gl_Position = CC_MVPMatrix * vec4(a_position, 1);
    //gl_Position = CC_MVPMatrix * (u_position + vec4(sin(CC_Time.w * direction.w) * direction.xyz, 1));
}
