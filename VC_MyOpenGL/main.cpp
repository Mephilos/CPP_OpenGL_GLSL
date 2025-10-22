
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"
#include "Model.h"
#include "TextureLoader.h"
#include "Skybox.h"
#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

Camera camera(glm::vec3(0.0f, 1.0f, 5.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}
void mouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
    ImGui_ImplGlfw_CursorPosCallback(window, xposIn, yposIn);
    if (ImGui::GetIO().WantCaptureMouse) 
    {
        return;
    }

    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if(firstMouse)
    {
        lastX=xpos;
        lastY=ypos;
        firstMouse = false;
    }
    
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    
    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
    if (ImGui::GetIO().WantCaptureMouse) 
    {
        return;
    }
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
    ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
    if (ImGui::GetIO().WantCaptureKeyboard) 
    {
        return;
    }
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void charCallback(GLFWwindow* window, unsigned int c) {
    ImGui_ImplGlfw_CharCallback(window, c);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) 
{
    ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
}

void processInput(GLFWwindow *window)
{
    if (ImGui::GetIO().WantCaptureKeyboard) 
    {
        return;
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard( FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}
int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "Fail to create GLFW WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }
    //OpenGL 실행(창)
    glfwMakeContextCurrent(window);
    //OpenGL 창 세팅
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    //OpenGL 창에 마우스 위치 세팅
    glfwSetCursorPosCallback(window, mouseCallback);
    //OpenGL 창에 스크롤 기능 세팅
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCharCallback(window, charCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);


    //마우스 입력 모드(커서 보이지 않게)
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //glad형식에 glfw함수 로드
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to Initialize GLAD" <<std::endl;
        return -1;
    }
    //모델링 로드 텍스처 y축으로 반전
    //깊이 버퍼 활성화
    glEnable(GL_DEPTH_TEST);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, false);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui_ImplOpenGL3_CreateFontsTexture();
    ImGui_ImplOpenGL3_CreateDeviceObjects();

    std::vector<std::string> skyboxFaces = {
        "resources/skybox/right.jpg",   // +X 방향 텍스처
        "resources/skybox/left.jpg",    // -X 방향 텍스처
        "resources/skybox/top.jpg",     // +Y 방향 텍스처
        "resources/skybox/bottom.jpg",  // -Y 방향 텍스처
        "resources/skybox/front.jpg",   // +Z 방향 텍스처
        "resources/skybox/back.jpg"     // -Z 방향 텍스처
    };
    
    //스카이 박스
    Shader skyboxShader("shader/skybox/skybox.vs", "shader/skybox/skybox.fs");
    Skybox skybox(skyboxFaces, skyboxShader); 
    
    stbi_set_flip_vertically_on_load(true);
    //셰이더 준비
    Shader modelShader("shader/modelLoading.vs","shader/modelLoading.fs");
    //모델 준비
    Model myModel("resources/backpack/backpack.obj");

    // Light properties
    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glm::vec3 lightAmbient(0.2f, 0.2f, 0.2f);
    glm::vec3 lightDiffuse(0.5f, 0.5f, 0.5f);
    glm::vec3 lightSpecular(1.0f, 1.0f, 1.0f);

    // Material properties (for now, a default shininess)
    float materialShininess = 32.0f;

    // Generate a default white texture for specular map if not provided by model
    unsigned int defaultSpecularMap;
    glGenTextures(1, &defaultSpecularMap);
    glBindTexture(GL_TEXTURE_2D, defaultSpecularMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, new unsigned char[3]{255, 255, 255});
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame; //시작시 last frame은 0.0f
        lastFrame = currentFrame; //lastFrame 갱신

        
        glfwPollEvents(); 
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Begin("Hello, ImGui!");
        ImGui::Text("This is some useful text.");
        ImGui::End();

        processInput(window);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), 
                                (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view       = camera.GetViewMatrix();

        skybox.Draw(view, projection);

        modelShader.use();
        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);
        modelShader.setVec3("viewPos", camera.Position);

        // Set light properties
        modelShader.setVec3("light.position", lightPos);
        modelShader.setVec3("light.ambient", lightAmbient);
        modelShader.setVec3("light.diffuse", lightDiffuse);
        modelShader.setVec3("light.specular", lightSpecular);

        // Set material properties
        modelShader.setFloat("shininess", materialShininess);
        // Bind default white texture for specular map if model doesn't provide one
        glActiveTexture(GL_TEXTURE1); // Use texture unit 1 for specular map
        glBindTexture(GL_TEXTURE_2D, defaultSpecularMap);
        modelShader.setInt("texture_specular1", 1); // Tell shader to use texture unit 1 for specular map

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        modelShader.setMat4("model", model);
        myModel.Draw(modelShader);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glDeleteTextures(1, &defaultSpecularMap);
    glfwTerminate();
    return 0;

}