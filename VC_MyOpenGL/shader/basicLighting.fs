#version 330 core
out vec4 FragColor;

in vec3 FragPos; //정점 위치
in vec3 Normal;  //법선 백터

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient 환경광
    float ambientStrength = 0.1;  
    vec3 ambient = ambientStrength * lightColor; // 광원 색에 강도 적용

    //Diffuse 확산광
    vec3 norm = normalize(Normal); // 법선 백터 정규화 
    vec3 lightDir = normalize(lightPos - FragPos); // 광원위치 -> 정규화
    float diff = max(dot(norm, lightDir),0.0); //정규화 법선,정규화 광원방향 내적(반사 값) 음수값은 버림.(최소 0.0)
    vec3 diffuse = diff * lightColor; //반사값 백터에 조명 백터 곱

    //Specular 정반사
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64); // pow 는 집중도 계산
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;     // 물체에 조명 적용
    FragColor = vec4(result, 1.0);    //최종 색상
}

