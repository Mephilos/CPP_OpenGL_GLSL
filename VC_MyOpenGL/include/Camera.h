#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class CameraHandler
{     
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 zaxis = glm::normalize(cameraTarget - cameraPos);
    glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(cameraUp),zaxis));
    glm::vec3 yaxis = glm::normalize(glm::normalize(cameraUp));
        
    glm::mat4 view = glm::mat4(1.0f);
    void viewMatrix()    
    {
        view[0][0] = xaxis.x;
        view[1][0] = xaxis.y;
        view[2][0] = xaxis.z;
        view[0][1] = yaxis.x;
        view[1][1] = yaxis.y;
        view[2][1] = yaxis.z;
        view[0][2] = zaxis.x;
        view[1][2] = zaxis.y;
        view[2][2] = zaxis.z;

        view[3][0] = -glm::dot(xaxis, cameraPos);
        view[3][1] = -glm::dot(yaxis, cameraPos);
        view[3][2] = -glm::dot(zaxis, cameraPos);
    }
};