#include "Renderer.h"


Renderer::Renderer(const float* vertices, size_t sizeInBytes,
                   unsigned int tex1, unsigned int tex2, 
                   const glm::vec3* positions, size_t positionCount)
    : texture1(tex1), texture2(tex2), objPositions(positions), count(positionCount) 
    {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeInBytes, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}
Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::Prepare(const glm::mat4& view, const glm::mat4& projection, Shader& shader)
{
    shader.use();
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
}
void Renderer::Draw(float time, Shader& shader)
{
    glBindVertexArray(VAO);

    for (size_t i = 0; i < 10; ++i)
    {
        // 모델 변환 초기화
        glm::mat4 model = glm::mat4(1.0f);
        // 위치 이동
        model = glm::translate(model, objPositions[i]);
        // 회전 각도 계산
        float angle = (i == 0) ? 20.0f : 20.0f *  static_cast<float>(i);
        // 시간 기반 회전 적용
        model = glm::rotate(model, glm::radians(angle * time), glm::vec3(1.0f, 0.3f, 0.5f));
        // 셰이더에 모델 행렬 전달
        shader.setMat4("model", model);
        // 실제 그리기
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}
