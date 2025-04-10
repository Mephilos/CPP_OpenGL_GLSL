#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 FragPos; //월드 공간상 정점위치
out vec3 Normal; //정점의 법선 백터


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	FragPos = vec3 (model * vec4(aPos, 1.0)); //위치 계산
	Normal = mat3(transpose(inverse(model))) *aNormal; //노멀 변환

	gl_Position = projection * view * vec4(FragPos, 1.0); //최종 클립 공간 변환
}

