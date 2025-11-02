#version 330 core

layout(location = 0) in vec3 aPos;      // 顶点位置
layout(location = 1) in vec3 aNormal;   // 法线
layout(location = 2) in vec2 aTexCoord; // 可选纹理坐标

uniform mat4 mat_model;
uniform mat4 mat_view;
uniform mat4 mat_projection;

out vec3 FragPos;    // 世界坐标
out vec3 Normal;     // 法线

void main()
{
    vec4 worldPos = mat_model * vec4(aPos, 1.0);
    FragPos = worldPos.xyz;

    Normal = mat3(transpose(inverse(mat_model))) * aNormal; // 法线变换

    gl_Position = mat_projection * mat_view * worldPos;
}
