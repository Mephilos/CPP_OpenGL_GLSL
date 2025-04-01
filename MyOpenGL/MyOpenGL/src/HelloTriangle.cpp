//
//  HelloTriangle.cpp
//  MyOpenGL
//
//  Created by TAEHO SIM on 3/30/25.
//

//

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
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);//너비 높이 제목 모니터 공유 컨텍스트
    std::cout << "뭐임 이거 한번 맞아??" << std::endl;
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //window
    
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
    
    float vertices[] = {
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),(void*)0);
    //GPU가 설정한 속성을 사용하게 되는 시점.
    glEnableVertexAttribArray(0);
    
    
    //바인딩 해제
    //설정이 끝났으니 이후 실수로 설정을 덮어쓰는 것을 방지하기 위해 해제
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    
    //쉐이더 코드(GLSL)
    const char* vertexShaderSource = "#version 330 core \n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() { \n"
    "   gl_Position = vec4(aPos, 1.0); \n"
    "}\n";
    
    const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";
    
    
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    // 프로그램 객체 생성 및 링크
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader); // 정점 쉐이더 붙이기
    glAttachShader(shaderProgram, fragmentShader); // 프래그먼트 쉐이더 붙이기
    glLinkProgram(shaderProgram); // 프로그램 링크 (GPU가 실행 가능한 형태로 연결)
    
    glDeleteShader(vertexShader); // 개별 쉐이더 삭제 (링크 이후 불필요)
    glDeleteShader(fragmentShader);
    // 렌더링 루프
    while (!glfwWindowShouldClose(window))
    {
        processInput(window); // 입력 처리
        
        // 배경색 설정 + 버퍼 초기화
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // (r, g, b, alpha)
        glClear(GL_COLOR_BUFFER_BIT);
        
        // 실제 렌더링
        glUseProgram(shaderProgram); // 셰이더 프로그램 사용
        glBindVertexArray(VAO); // 정점 배열 객체 바인딩
        glDrawArrays(
                     GL_TRIANGLES, // 도형 타입: 삼각형
                     0,            // 시작 인덱스
                     3             // 정점 개수
                     );
        
        glfwSwapBuffers(window); // 버퍼 스왑 (더블 버퍼링)
        glfwPollEvents();        // 이벤트 처리 (입력 등)
    }
    
    // 자원 정리
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    glfwTerminate(); // GLFW 종료
    return 0;
    
}
