#include "../include/Camera.h"

// 생성자: 위치, 상단방향, 회전 초기값
Camera::Camera(glm::vec3 position, glm::vec3 worldUp, float yaw, float pitch)
    : Position(position), WorldUp(worldUp), Yaw(yaw), Pitch(pitch), Zoom(45.0f)
{
    updateCameraVectors();  // 초기 방향
}

//  View 행렬 수동 
glm::mat4 Camera::GetViewMatrix() const 
{
    // 뷰 메트릭스 초기화
    glm::mat4 view(1.0f); 

    // 회전 행렬 구성
    view[0][0] = Right.x;
    view[1][0] = Right.y;
    view[2][0] = Right.z;

    view[0][1] = Up.x;
    view[1][1] = Up.y;
    view[2][1] = Up.z;

    view[0][2] = -Front.x;
    view[1][2] = -Front.y;
    view[2][2] = -Front.z;

    // 평행 이동
    view[3][0] = -glm::dot(Right, Position);
    view[3][1] = -glm::dot(Up, Position);
    view[3][2] =  glm::dot(Front, Position); // OpenGL 특성 

    return view;
}
    // zk메라 이동속도
void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) 
{
    float velocity = 2.5f * deltaTime;
    if (direction == FORWARD)
        Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}
    //마우스 입력
void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch) 
{
    xoffset *= 0.1f;
    yoffset *= 0.1f;

    Yaw   += xoffset;
    Pitch += yoffset;

    if (constrainPitch) {
        if (Pitch > 89.0f) Pitch = 89.0f;
        if (Pitch < -89.0f) Pitch = -89.0f;
    }

    updateCameraVectors(); // 회전 변경 후 방향 업데이트
}

void Camera::ProcessMouseScroll(float yoffset) 
{
    Zoom -= yoffset;
    if (Zoom < 1.0f) Zoom = 1.0f;
    if (Zoom > 45.0f) Zoom = 45.0f;
}

//  방향 벡터 계산: Yaw / Pitch 기준
void Camera::updateCameraVectors() 
{
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);  // 카메라 시선 방향

    Right = glm::normalize(glm::cross(Front, WorldUp)); // 오른쪽 축
    Up    = glm::normalize(glm::cross(Right, Front));   // 직교화된 위쪽 축
}