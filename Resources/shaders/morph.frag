#ifdef GL_ES
precision mediump float;
#endif

uniform vec4 u_color;

varying vec2 v_texcoord;
varying vec4 v_normal;

void main(void)
{
    vec2 texcoord = v_texcoord;
	gl_FragColor = u_color * vec4(v_normal.xyz / 2.0 + vec3(.5,.5,.5), 1);
}
