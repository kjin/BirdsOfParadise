// Actually used as direction
attribute vec3 a_position;
attribute vec2 a_texcoord;
attribute vec3 a_normal;

uniform vec4 u_position;

varying vec2 v_texcoord;
varying vec4 v_normal;

void main()
{
    v_normal = vec4(a_normal, 0);
    v_texcoord = a_texcoord;
    gl_Position = CC_MVPMatrix * vec4(a_position, 1);
    //gl_Position = CC_MVPMatrix * (u_position + vec4(sin(CC_Time.w * direction.w) * direction.xyz, 1));
}
