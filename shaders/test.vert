//~ fa-1, fa-2, fu-1, fu-2, fu-3

uniform mat4 u_ModelMatrix;
uniform mat4 u_ProjectionMatrix;
uniform mat4 u_ViewMatrix;

attribute vec3 a_Position;
attribute vec2 a_TextureCoordinates;

varying vec2 v_TexCoords;

void main()
{
	gl_Position = u_ProjectionMatrix * u_ViewMatrix * u_ModelMatrix * vec4(a_Position, 1.0);
	v_TexCoords = a_TextureCoordinates;
}