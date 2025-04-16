#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include "Shader.h"

class Skybox 
{
public:
    //생성자
    Skybox(const std::vector<std::string>& faces, const Shader& shader);
    
    void Draw(const glm::mat4& view, const glm::mat4& projection);
    
private:
    unsigned int VAO, VBO;
    unsigned int cubemapTexture;
    Shader shader;
};