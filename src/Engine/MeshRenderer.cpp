#include "MeshRenderer.h"

#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Maths.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Environment.h"
#include "Camera.h"

#include "glew.h"

#include <string>

namespace HGE
{
	void MeshRenderer::onRender()
	{
		if (Render)
		{
			glUseProgram(program->ID);
			glBindVertexArray(mesh->ID);
			glBindTexture(GL_TEXTURE_2D, texture->ID);

			for (int i = 0; i < program->uniforms.size(); i++)
			{
				ShaderProgram::ShaderUniform tmp = program->uniforms.at(i);
				if (tmp.name == "u_ModelMatrix")
				{
					glUniformMatrix4fv(tmp.ID, 1, GL_FALSE, value_ptr(GetEntity()->GetTransform()->GetModelMatrix()));
				}
				else if (tmp.name == "u_ProjectionMatrix")
				{
					if (Orthographic)
					{
						glUniformMatrix4fv(tmp.ID, 1, GL_FALSE, value_ptr(ORTHOGRAPHIC_MATRIX));
					}
					else
					{
						glUniformMatrix4fv(tmp.ID, 1, GL_FALSE, value_ptr(PERSPECTIVE_MATRIX));
					}
				}
				else if (tmp.name == "u_ViewMatrix")
				{
					glUniformMatrix4fv(tmp.ID, 1, GL_FALSE, value_ptr(inverse(GetCore()->Environment->mainCamera->GetViewMatrix())));
				}
				else if (tmp.name == "u_LightColour")
				{
					// apply LightColour
					glUniform3fv(tmp.ID, 1, glm::value_ptr(vec3(1,1,1)));
				}
				else if (tmp.name == "u_LightPosition")
				{
					// apply Light Position
					glUniform3fv(tmp.ID, 1, glm::value_ptr(vec3(0, 100, 0)));
				}
				else if (tmp.name == "u_LightAmbientStrength")
				{
					// apply ambient light strength
					glUniform1f(tmp.ID, 0.5f);
				}
				else if (tmp.name == "u_Texture")
				{
					glUniform1i(texture->ID, 1);
				}
			}

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glDrawArrays(GL_TRIANGLES, 0, mesh->VertexCount);
			glDisable(GL_CULL_FACE);
			glDisable(GL_DEPTH_TEST);

			glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(0);
			glUseProgram(0);
		}
	}

	void MeshRenderer::SetMesh(std::shared_ptr<Mesh> _mesh) { mesh = _mesh; }
	void MeshRenderer::SetShader(std::shared_ptr<ShaderProgram> _program) { program = _program; }
	void MeshRenderer::SetTexture(std::shared_ptr<Texture> _texture) { texture = _texture; }
}