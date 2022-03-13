//~ fu-7

uniform sampler2D u_Texture;

varying vec2 v_TexCoords;

void main()
{
	vec4 tex = texture2D(u_Texture, v_TexCoords);
	gl_FragColor = tex;
}