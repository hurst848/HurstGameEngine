//~ fu-4, fu-5, fu-6, fu-7

uniform sampler2D u_Texture;

uniform vec3 u_LightColour;
uniform vec3 u_LightPosition;
uniform float u_LightAmbientStrength;

varying vec2 v_TexCoords;
varying vec3 v_Normal;
varying vec3 v_FragmentPosition;

void main()
{
	vec3 ambientLight = u_LightAmbientStrength * u_LightColour;
	
	vec3 norm = normalize(v_Normal);
	vec3 lightDirection = normalize(u_LightPosition - v_FragmentPosition);
	float diff = max(dot(norm, u_LightColour), 0.0);
	vec3 diffuseLight = diff * u_LightColour;

	vec3 light = ambientLight + diffuseLight;
	vec4 tex = texture2D(u_Texture, v_TexCoords);
	
	gl_FragColor = vec4(light, 1.0) * tex;
}