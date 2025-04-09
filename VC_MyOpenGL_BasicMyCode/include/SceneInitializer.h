#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class SceneInitializer
{
public:
    static GLFWwindow* Init(int width, int height, const std::string& title);

private:
    SceneInitializer() = delete;
};