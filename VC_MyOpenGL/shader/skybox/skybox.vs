#version 330 core
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    // 뷰 행렬에서 위치 부분 제거 (rotation만 유지)
    mat4 rotView = mat4(mat3(view));
    vec4 pos = projection * rotView * vec4(aPos, 1.0);
    gl_Position = pos.xyww; //z삭제해서 깊이값 1.0 고정 -> 무조건 뒤에 그려짐
    TexCoords = aPos;
}