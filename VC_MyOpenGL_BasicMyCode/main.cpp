#include "Shader.h"
#include "Camera.h"
#include "Input.h"
#include "Renderer.h"
#include "TextureLoader.h"
#include "ObjectLayout.h"
#include "SceneInitializer.h"
#include "ShaderManager.h"
#include "ObjMesh.h"
#include "GameManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

unsigned int SCR_WIDTH = 800;
unsigned int SCR_HEIGHT = 600;

auto [vertices, vertexSize] = ObjMesh::GetObjVertices();
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f),
              glm::vec3(0.0f, 1.0f, 0.0f),
              -90.0f,
              0.0f);
float deltaTime = 0.0f;
float lastFrame = 0.0f; 

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouseCallback(GLFWwindow* window, double xposIn, double yposIn);

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

void processInput(GLFWwindow *window);

int main()
{
    GLFWwindow* window = SceneInitializer::Init(SCR_WIDTH,SCR_HEIGHT,"LearnOpenGL");
    if(!window) { return -1; }

    ShaderManager::LoadShader( "basic", "../shader/GLshader.vs", "../shader/GLshader.fs" );
    Shader& shader = ShaderManager::GetShader("basic");

    const std::vector<glm::vec3>& Objpositions = ObjectLayout::DefaultLayout();

    unsigned int texture1 = TextureLoader::LoadTexture2D("../resources/container.jpg");
    unsigned int texture2 = TextureLoader::LoadTexture2D("../resources/awesomeface.png");
    
    shader.use();
    shader.setInt("texture1", 0);
    shader.setInt("texture2", 1);
    
    
    Renderer renderer(vertices, vertexSize ,texture1, texture2, Objpositions.data(), Objpositions.size());
   
    //Game 시작: 루프 작동
    GameManager::Run(window, shader, renderer, camera); 

    glfwTerminate();
    return 0;
}
