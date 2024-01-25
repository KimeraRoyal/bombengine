#version 330 core

uniform sampler2D in_Texture;

in vec2 TexCoord;

layout(location = 0) out vec4 out_FragColor;

void main()
{
    vec4 tex = texture(in_Texture, TexCoord);
    out_FragColor = vec4(tex.rgb, 1.0);
}