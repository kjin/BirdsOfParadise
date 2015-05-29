#ifdef GL_ES
precision mediump float;
#endif

uniform vec4 u_color;

void main(void)
{
	gl_FragColor = u_color * vec4(vec3(.5,.5,.5), 1);
}
