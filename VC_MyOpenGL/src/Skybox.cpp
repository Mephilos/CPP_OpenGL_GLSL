#include "Skybox.h"
#include "TextureLoader.h"
#include <glm/gtc/type_ptr.hpp>

Skybox::Skybox(const std::vector<std::string>& faces , const Shader& shader)
    : shader(shader)
{
    float skyboxVertices[] = {
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,  
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f, 
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,   
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,   
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,   
         1.0f, -1.0f,  1.0f, 
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,   
         1.0f,  1.0f, -1.0f,   
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, 
        -1.0f,  1.0f,  1.0f,  
        -1.0f,  1.0f, -1.0f,
        
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,  
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f, 
        -1.0f, -1.0f,  1.0f,   
         1.0f, -1.0f,  1.0f
    };

    cubemapTexture = TextureLoader::LoadCubemap(faces);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
}

void Skybox::Draw(const glm::mat4& view, const glm::mat4& projection)
{
    glDepthFunc(GL_LEQUAL);
    shader.use();
    shader.setMat4("view", glm::mat4(glm::mat3(view)));
    shader.setMat4("projection", projection);

    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);
}