#version 330 core
out vec4 FragColor;

in vec3 FragPos; //정점 위치
in vec3 Normal;  //법선 백터


//마테리얼(재료) 구조체
struct Material 
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};
//빛 구조체
struct Light
{
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
    // ambient 환경광 
    vec3 ambient = light.ambient * material.ambient;

    //Diffuse 확산광
    vec3 norm = normalize(Normal); // 법선 백터 정규화 
    vec3 lightDir = normalize(light.position - FragPos); // 광원위치 -> 정규화
    float diff = max(dot(norm, lightDir),0.0); //정규화 법선,정규화 광원방향 내적(반사 값) 음수값은 버림.(최소 0.0)
    vec3 diffuse = light.diffuse * (diff * material.diffuse); //반사값 백터에 조명 백터 곱

    //Specular 정반사
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); // pow 는 집중도 계산
    vec3 specular = light.specular * (spec * material.specular);

    vec3 result = ambient + diffuse + specular;    // 물체에 조명 적용
    FragColor = vec4(result, 1.0);    //최종 색상
}

