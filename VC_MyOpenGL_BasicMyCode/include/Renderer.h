#pragma once

#include "Shader.h"
#include <glad/glad.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Renderer
{
public:
    Renderer(const float* vertices, size_t sizeInBytes, 
             unsigned int texture1, unsigned int texture2, 
             const glm::vec3* positions, size_t positionCount);
    ~Renderer();

    void Prepare(const glm::mat4& view, const glm::mat4& projection, Shader& shader);
    void Draw(float time, Shader& shader);

private:

    unsigned int VAO, VBO;
    unsigned int texture1, texture2;
    
    const glm::vec3* objPositions;
    size_t count;
};