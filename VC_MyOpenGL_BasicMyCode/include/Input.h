#pragma once

#include <GLFW/glfw3.h>
    //마우스 이동(마우스 위치)
void mouseCallback(GLFWwindow* window, double xposIn, double yposIn);
    //확대
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    //입력(키보드)
void processInput(GLFWwindow* window);