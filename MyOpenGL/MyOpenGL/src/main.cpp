//
//  main.cpp
//  MyOpenGL
//
//  Created by TAEHO SIM on 3/28/25.
//

// main.cpp

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    // GLFW 초기화
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Mac 호환성
#endif

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // GLAD 초기화
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // OpenGL viewport 설정
    glViewport(0, 0, 800, 600);

    // 창 크기 변경 콜백 등록
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 렌더링 루프
    while (!glfwWindowShouldClose(window))
    {
        // 입력 처리
        processInput(window);

        // 색상 버퍼 초기화
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // 배경 색
        glClear(GL_COLOR_BUFFER_BIT);

        // 버퍼 교환 + 이벤트 처리
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 종료 처리
    glfwTerminate();
    return 0;
}
