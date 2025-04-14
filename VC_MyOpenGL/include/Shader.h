//
//  Shader.h
//  MyOpenGL
//
//  Created by TAEHO SIM on 3/31/25.
//

#ifndef Shader_h
#define Shader_h

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

class Shader
{
public:
    unsigned int ID; // 셰이더 프로그램의 ID를 저장하는 변수입니다.

    // 생성자: 셰이더를 읽고 빌드합니다.
    // 이 생성자는 셰이더 프로그램을 초기화하는 데 필요한 모든 단계를 수행합니다.
    // 주어진 경로에서 정점 셰이더와 프래그먼트 셰이더의 소스 코드를 읽어와야 합니다.
    // 그런 다음, 이를 컴파일하고 링크하여 최종적으로 사용할 수 있는 셰이더 프로그램을 생성합니다.
    // 이 과정은 OpenGL에서 그래픽스를 렌더링하는 데 필요한 필수 단계입니다.
    Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr)
    {
        // 1. 파일 경로에서 정점 및 프래그먼트 소스 코드를 가져옵니다.
        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        std::ifstream gShaderFile;

        // ifstream 객체가 예외를 발생시킬 수 있도록 설정합니다.
        // 이렇게 하면 파일을 여는 도중 문제가 발생할 경우 예외를 발생시켜 적절한 오류 처리를 할 수 있습니다.
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            std::stringstream vShaderStream, fShaderStream;

            // 파일을 엽니다. 이 단계에서 주어진 경로에 있는 파일을 열어야 합니다.
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);

            // 파일의 내용을 스트림으로 읽어옵니다. 이렇게 함으로써 파일의 모든 내용을 메모리에 저장할 수 있습니다.
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            // 파일 핸들러를 닫습니다. 파일을 다 사용한 후에는 반드시 닫아야 메모리 누수를 방지할 수 있습니다.
            vShaderFile.close();
            fShaderFile.close();

            // 스트림을 문자열로 변환합니다. 이제 셰이더 소스 코드가 문자열 형태로 준비되었습니다.
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

            //지오매트리 패스가 채워져 있을 때 실행하는 지오매트리 파일 읽음.
            if(geometryPath != nullptr)
            {
                gShaderFile.open(geometryPath);
                std::stringstream gShaderStream;
                //스트림에 저장
                gShaderStream << gShaderFile.rdbuf();
                gShaderFile.close();
                //코드에 변환하여 저장
                geometryCode = gShaderStream.str();
            }
        }
        catch (std::ifstream::failure& e)
        {
            // 파일을 성공적으로 읽지 못했을 때의 오류 메시지를 출력합니다.
            // 이 오류는 파일이 존재하지 않거나 읽기 권한이 없을 때 발생할 수 있습니다.
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        if (!vertexCode.length()) {
            std::cerr << " Failed to load vertex shader: " << vertexPath << std::endl;
            std::cerr << " 현재 경로: " << std::filesystem::current_path() << std::endl;
        }
        if (!fragmentCode.length()) {
            std::cerr << " Failed to load fragment shader: " << fragmentPath << std::endl;
            std::cerr << " 현재 경로: " << std::filesystem::current_path() << std::endl;
        }
        if (!geometryCode.length()) {
            std::cerr << " Failed to load fragment shader: " << fragmentPath << std::endl;
            std::cerr << " 현재 경로: " << std::filesystem::current_path() << std::endl;
        }

        const char* vShaderCode = vertexCode.c_str(); // 정점 셰이더 코드의 C 문자열 포인터
        const char* fShaderCode = fragmentCode.c_str(); // 프래그먼트 셰이더 코드의 C 문자열 포인터

        // 2. 셰이더를 컴파일합니다.
        // 정점 셰이더와 프래그먼트 셰이더를 각각 컴파일하여 오류가 없는지 확인합니다.
        // 이 단계에서 OpenGL은 셰이더 소스 코드를 기계어로 변환하여 GPU에서 실행할 수 있도록 합니다.
        unsigned int vertex, fragment;
        vertex = glCreateShader(GL_VERTEX_SHADER); // 정점 셰이더 객체를 생성합니다.
        glShaderSource(vertex, 1, &vShaderCode, NULL); // 셰이더 소스 코드를 설정합니다.
        glCompileShader(vertex); // 셰이더를 컴파일합니다.
        checkCompileErrors(vertex, "VERTEX"); // 컴파일 오류를 확인합니다.

        fragment = glCreateShader(GL_FRAGMENT_SHADER); // 프래그먼트 셰이더 객체를 생성합니다.
        glShaderSource(fragment, 1, &fShaderCode, NULL); // 셰이더 소스 코드를 설정합니다.
        glCompileShader(fragment); // 셰이더를 컴파일합니다.
        checkCompileErrors(fragment, "FRAGMENT"); // 컴파일 오류를 확인합니다.
        //지오메트리 컴파일 (기하(도형) 컴파일)
        unsigned int geometry;
        if(geometryPath != nullptr)
        {
            const char * gShaderCode = geometryCode.c_str();
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, NULL);
            glCompileShader(geometry);
            checkCompileErrors(geometry, "GEOMETRY");
        }
        // 셰이더 프로그램을 생성합니다.
        // 컴파일된 셰이더를 프로그램에 첨부하고 링크하여 최종적으로 사용할 수 있는 셰이더 프로그램을 만듭니다.
        // 이 과정은 OpenGL이 셰이더를 실행하기 위해 필요한 모든 정보를 결합하는 단계입니다.
        ID = glCreateProgram(); // 셰이더 프로그램 객체를 생성합니다.
        glAttachShader(ID, vertex); // 정점 셰이더를 프로그램에 첨부합니다.
        glAttachShader(ID, fragment); // 프래그먼트 셰이더를 프로그램에 첨부합니다.
        if(geometryPath != nullptr) // 지오메트리 경로가 있을ㄷ 때 기하 세이더를 프로그램에 첨부.
            glAttachShader(ID, geometry);
        glLinkProgram(ID); // 프로그램을 링크하여 최종적으로 사용할 수 있는 셰이더 프로그램을 완성합니다.
        checkCompileErrors(ID, "PROGRAM"); // 링크 오류를 확인합니다.

        // 셰이더는 프로그램에 링크되었으므로 더 이상 필요하지 않으므로 삭제합니다.
        // 이렇게 함으로써 메모리를 해제하고 불필요한 리소스를 줄일 수 있습니다.
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    // 셰이더를 활성화합니다.
    // 이 함수는 OpenGL에게 현재 사용할 셰이더 프로그램을 설정합니다.
    // 이 함수가 호출되면 이후의 렌더링 작업은 이 셰이더 프로그램을 사용하게 됩니다.
    void use() const
    {
        glUseProgram(ID); // 현재 셰이더 프로그램을 활성화합니다.
    }

    // 유니폼 값을 설정하는 유틸리티 함수입니다.
    // 셰이더 내에서 사용할 수 있도록 부울, 정수 및 부동 소수점 값을 설정합니다.
    // 이 함수는 셰이더에서 사용하는 유니폼 변수를 업데이트하여 렌더링 결과에 영향을 미치도록 합니다.
    void setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); // 부울 값을 유니폼으로 설정합니다.
    }
    void setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value); // 정수 값을 유니폼으로 설정합니다.
    }
    void setFloat(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value); // 부동 소수점 값을 유니폼으로 설정합니다.
    }
    void setVec2(const std::string &name, const glm::vec2 &value) const
    { 
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
    }
    void setVec2(const std::string &name, float x, float y) const
    { 
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    { 
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    { 
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    { 
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
    }
    void setVec4(const std::string &name, float x, float y, float z, float w) const
    { 
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }


private:
    // 컴파일 오류를 확인하는 함수입니다.
    // 셰이더의 컴파일 또는 프로그램의 링크 과정에서 발생한 오류를 확인하고 출력합니다.
    // 이 함수는 디버깅을 도와주며, 어떤 문제가 발생했는지 사용자에게 알리는 역할을 합니다.
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success; // 컴파일 또는 링크 성공 여부를 저장하는 변수입니다.
        char infoLog[1024]; // 오류 메시지를 저장할 버퍼입니다.
        if (type != "PROGRAM") // 셰이더의 컴파일 오류를 확인합니다.
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success); // 컴파일 상태를 가져옵니다.
            if (!success) // 컴파일이 실패한 경우
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog); // 오류 메시지를 가져옵니다.
                std::cout << "ERROR::SHADER::COMPILATION_ERROR of type: " << type << "\n"
                          << infoLog << "\n -- --------------------------------------------------- -- " << std::endl; // 오류 메시지를 출력합니다.
            }
        }
        else // 프로그램의 링크 오류를 확인합니다.
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success); // 링크 상태를 가져옵니다.
            if (!success) // 링크가 실패한 경우
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog); // 오류 메시지를 가져옵니다.
                std::cout << "ERROR::PROGRAM::LINKING_ERROR of type: " << type << "\n"
                          << infoLog << "\n -- --------------------------------------------------- -- " << std::endl; // 오류 메시지를 출력합니다.
            }
        }
    }
    
};
#endif /* Shader_h */
