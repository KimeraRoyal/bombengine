#version 330 core

uniform sampler2D in_Texture;

in vec3 in_FragPos;
in vec3 in_Normal;
in vec2 in_TexCoord;

layout(location = 0) out vec4 out_FragColor;

void main()
{
    vec4 tex = texture2D(in_Texture, in_TexCoord);
    out_FragColor = vec4(tex.rgb, 1.0);
}