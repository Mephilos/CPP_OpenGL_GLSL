#version 330 core
out vec4 FragColor;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};

struct DirLight
{
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight
{
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight
{
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define NR_POINT_LIGHTS 4

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform Material material;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    //빛방향 정규화
    vec3 lightDir = normalize(-light.direction);
    //난반사
    float diff = max(dot(normal, lightDir), 0.0);
    //반사 방향
    vec3 reflectDir = reflect(-lightDir, normal);
    //정반사(빛 반향에 따라 거울처럼 하이라이트 되는 부분)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    //설정
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    //빛 방향 구하기
    vec3 lightDir = normalize(light.position - fragPos);
    //법선, 빛방향 내적 구하기(난반사)
    float diff = max(dot(normal, lightDir), 0.0);
    //법선, 빛방향 으로 반사 방향 구하기 = reflect: -lightDir -2*(dot(normal, -lightDir))*normal
    vec3 reflectDir = reflect(-lightDir, normal);
    //반사값 shininess는 specular 반사광의 세기를 정함 dot은 시야방향(aka카메라forward)과 반사방향의 내적으로 일치도를 구하기 위함
    //max는 cos값을 0~1로 제한하기 위함
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    //거리
    float distance = length(light.position - fragPos);
    //거리에 따른 빛세기 구하기
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);
    
    float diff = max(dot(normal, lightDir), 0.0);
    
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
    //스팟라이트의 빛의 방향 법선백터의 cos𝜭
    float theta = dot(lightDir, normalize(-light.direction)); 
    //보간 거리
    float epsilon = light.cutOff - light.outerCutOff;
    //0~1로 점진적으로 보간 (theta - light.outerCutOff) / epsilon은 보간 구간을 구하는 것.
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;
    return (ambient + diffuse + specular);
}

void main()
{   
    //기본 설정 
    //법선
    vec3 norm = normalize(Normal);
    //방향
    vec3 viewDir = normalize(viewPos - FragPos);


    vec3 emission = texture(material.emission, TexCoords).rgb;
    //방향광
    vec3 result = CalcDirLight(dirLight, norm, viewDir);
    //포인트라이트(복수 처리)
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);    
    //스팟라이트
    result += CalcSpotLight(spotLight, norm, FragPos, viewDir);    
    result += (emission * 0.4f);
    FragColor = vec4(result, 1.0);
}