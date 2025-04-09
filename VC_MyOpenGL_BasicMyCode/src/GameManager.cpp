#include "GameManager.h"

extern float deltaTime;
extern float lastFrame;
extern unsigned int SCR_WIDTH;
extern unsigned int SCR_HEIGHT;

void GameManager::Run(GLFWwindow* window, Shader& shader, Renderer& renderer, Camera& camera)
{
    while (!glfwWindowShouldClose(window))
    {
        // 프레임 간 시간 계산
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // 사용자 입력 처리
        processInput(window);

        // 화면 초기화
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 카메라 설정
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)SCR_WIDTH / (float)SCR_HEIGHT,
                                                0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();

        // 렌더러 준비 및 그리기
        renderer.Prepare(view, projection, shader);
        renderer.Draw(currentFrame, shader);

        // 버퍼 교환 + 이벤트 처리
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}