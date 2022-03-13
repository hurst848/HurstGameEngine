#include "Shader.h"

#include <fstream>
#include <iostream>

namespace HGE
{
	void Shader::Load(const std::string& _path)
	{
		std::string line;
		std::ifstream vis(_path);
		std::string input;
		bool flagsDetected = false;
		for (int i = 0; std::getline(vis, line); i++)
		{
			if (line.find("//~") != std::string::npos)
			{
				evaluateFlags(line);
				flagsDetected = true;
			}
			else
			{
				input += line;
			}
		}
		const GLchar* rlcode = input.c_str();
		code = rlcode;
		GLint success = 0;
		vis.close();
		std::cout << _path << "\n";
		if (_path.find(".vert") != std::string::npos)
		{
			ID = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (_path.find(".frag") != std::string::npos)
		{
			ID = glCreateShader(GL_FRAGMENT_SHADER);
		}
		glShaderSource(ID, 1, &rlcode, NULL);
		glCompileShader(ID);
		glGetShaderiv(ID, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			GLint maxLength = 0;
			glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(ID, maxLength, &maxLength, &errorLog.at(0));
			std::cout << &errorLog.at(0) << std::endl;
			throw std::exception();
		}
	}

	void Shader::evaluateFlags(std::string _line)
	{
		if (_line.find("fa-1") != std::string::npos) { flags.push_back("fa-1"); }
		if (_line.find("fa-2") != std::string::npos) { flags.push_back("fa-2"); }
		if (_line.find("fa-3") != std::string::npos) { flags.push_back("fa-3"); }
		if (_line.find("fu-1") != std::string::npos) { flags.push_back("fu-1"); }
		if (_line.find("fu-2") != std::string::npos) { flags.push_back("fu-2"); }
		if (_line.find("fu-3") != std::string::npos) { flags.push_back("fu-3"); }
		if (_line.find("fu-4") != std::string::npos) { flags.push_back("fu-4"); }
		if (_line.find("fu-5") != std::string::npos) { flags.push_back("fu-5"); }
		if (_line.find("fu-6") != std::string::npos) { flags.push_back("fu-6"); }
		if (_line.find("fu-7") != std::string::npos) { flags.push_back("fu-7"); }
	}

	Shader::~Shader()
	{
		glDeleteShader(ID);
	}

	void ShaderProgram::AddShader(std::shared_ptr<Shader> _shader)
	{
		shaders.push_back(_shader);
	}

	void ShaderProgram::Compile()
	{
		ID = glCreateProgram();

		std::vector<std::string> usedFlags;

		for (int i = 0; i < shaders.size(); i++)
		{
			glAttachShader(ID, shaders.at(i)->ID);
		}

		for (int i = 0; i < shaders.size(); i++)
		{

			for (int j = 0; j < shaders.at(i)->flags.size(); j++)
			{
				std::string tmp = shaders.at(i)->flags.at(j);
				if (tmp == "fa-1")
				{
					glBindAttribLocation(ID, 0, "a_Position");
				}
				else if (tmp == "fa-2")
				{
					glBindAttribLocation(ID, 1, "a_TextureCoordinates");
				}
				else if (tmp == "fa-3")
				{
					glBindAttribLocation(ID, 2, "a_Normal");
				}
			}
			
		}
		glLinkProgram(ID);

		int success = 0;
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success) {
			GLint maxLength = 0;
			glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetProgramInfoLog(ID, maxLength, &maxLength, &errorLog.at(0));
			std::cout << &errorLog.at(0) << std::endl;
			throw std::exception();
		}

		for (int i = 0; i < shaders.size(); i++)
		{
			glDetachShader(ID, shaders.at(i)->ID);
		}

		for (int i = 0; i < shaders.size(); i++)
		{
			for (int j = 0; j < shaders.at(i)->flags.size(); j++)
			{
				std::string tmp = shaders.at(i)->flags.at(j);

				if (tmp == "fu-1")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_ModelMatrix");
					tmp.name = "u_ModelMatrix";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-2")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_ProjectionMatrix");
					tmp.name = "u_ProjectionMatrix";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-3")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_ViewMatrix");
					tmp.name = "u_ViewMatrix";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-4")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_LightColour");
					tmp.name = "u_LightColour";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-5")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_LightPosition");
					tmp.name = "u_LightPosition";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-6")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_LightAmbientStrength");
					tmp.name = "u_LightAmbientStrength";
					uniforms.push_back(tmp);
				}
				else if (tmp == "fu-7")
				{
					ShaderUniform tmp;
					tmp.ID = glGetUniformLocation(ID, "u_Texture");
					tmp.name = "u_Texture";
					uniforms.push_back(tmp);
				}
			}
		
		}
	}
}