#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 viewPos;   // 摄像机位置
uniform Material material;
uniform Light light;

void main()
{
    // 1. 归一化法线
    vec3 norm = normalize(Normal);

    // 2. 光照方向
    vec3 lightDir = normalize(light.position - FragPos);

    // 3. 视线方向
    vec3 viewDir = normalize(viewPos - FragPos);

    // 4. 半向量 (Blinn-Phong)
    vec3 halfwayDir = normalize(lightDir + viewDir);

    // 5. 环境光
    vec3 ambient = light.ambient * material.ambient;

    // 6. 漫反射
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * material.diffuse;

    // 7. 高光反射
    float spec = pow(max(dot(norm, halfwayDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * material.specular;

    // 8. 合成颜色
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}
