#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement
{
    FORWARD, 
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
public:
    
    glm::vec3 Position;  // 카메라 위치 (월드)
    glm::vec3 Front;     // 카메라가 바라보는 방향
    glm::vec3 Up;        // 위쪽 벡터 
    glm::vec3 Right;     // 오른쪽 벡터
    glm::vec3 WorldUp;   // 월드 기준 Up (0,1,0)


     // 마우스 사용을 위한 오일러 각
     float Yaw;
     float Pitch;
    //확대 ()
     float Zoom;
    
     //카메라 생성자
     Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
            float yaw = -90.0f,
            float pitch = 0.0f);

    //카메라 뷰 행렬 함수
    glm::mat4 GetViewMatrix() const;

    //카보드 입력
    void ProcessKeyboard(Camera_Movement direction, float deltTime);
    //마우스 요 피치
    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
    //줌
    void ProcessMouseScroll(float yoffset);

private:
    //백터 방향 업데이트
    void updateCameraVectors();
};