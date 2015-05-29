// Actually used as direction
attribute vec4 a_position;

uniform vec4 u_position;

void main()
{
    vec4 direction = a_position;
    gl_Position = CC_MVPMatrix * (u_position + vec4(sin(CC_Time.w * direction.w) * direction.xyz, 1));
}
