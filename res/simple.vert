#version 330 core
layout(location=0) in vec3 in_Position;
layout(location=1) in vec3 in_Normal;
layout(location=2) in vec2 in_TexCoord;

uniform mat4 in_View;
uniform mat4 in_Projection;
uniform mat4 in_Model;

out vec2 TexCoord;

out vec3 Normal;
out vec3 FragPos;

void main()
{
	gl_Position = in_Projection * in_View * in_Model * vec4(in_Position, 1.0);
	TexCoord = in_TexCoord;

	Normal = mat3(in_Model) * in_Normal;
	FragPos = vec3(in_Model * vec4(in_Position, 1.0));
}