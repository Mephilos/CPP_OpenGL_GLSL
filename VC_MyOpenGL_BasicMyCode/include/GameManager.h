#pragma once

#include "Shader.h"
#include "Camera.h"
#include "Renderer.h"
#include "Input.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class GameManager
{
public:
    static void Run(GLFWwindow* window, Shader& shader, Renderer& renderer, Camera& camera);
};