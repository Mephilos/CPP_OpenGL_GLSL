#pragma once

#include "Shader.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <vector>

#define MAX_BONE_INFLUENCE 4

struct Vertex
{
    glm::vec3 Position;
    //표면의 법선 백터
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    //접선 노멀 매핑용
    glm::vec3 Tangent;
    // 접선과 노멀의 수직인 보조 백터
    glm::vec3 Bitangent;
        //본의 정보 (id)
        int m_BoneIDs[MAX_BONE_INFLUENCE]; //define 설정 최대 4개
        //본의 정점에 영향을 주는 가중치
        float m_Weights[MAX_BONE_INFLUENCE]; 
};

struct Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh
{
public:
    //정점
    std::vector<Vertex>       vertices;
    //인덱스
    std::vector<unsigned int> indices;
    //텍스처 리스트
    std::vector<Texture>      textures;
    //정점 배열 정보를 저장하고 있는 객체가 될 예정
    unsigned int VAO;

    //생성자: 정점 인덱스 텍스처 정보를 받아서 생성
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures)
    {   
        this -> vertices = vertices;
        this -> indices = indices;
        this -> textures = textures;
        //openGL 객체를 초기화 vao,vbo,ebo
        setupMesh();
    }

    void Draw(Shader &shader)
    {
        //텍스처 카운터(초기화)
        unsigned int diffuseNr  = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr   = 1;
        unsigned int heightNr   = 1;

        //텍스처 바인딩 루프
        for(unsigned int i = 0 ; i < textures.size(); i++)
        {
            // i 번째 텍스처 유닛 활성화
            glActiveTexture(GL_TEXTURE0 + i); 

            std::string number;
            std::string name = textures[i].type;
            
            // 텍스처 종류 별로 이름 붙이기
            if(name == "texture_diffuse")
            {
                number = std::to_string(diffuseNr++);
            }
            else if(name == "texture_specular")
            {
                number = std::to_string(specularNr++);
            }
            else if(name == "texture_normal")
            {
                number = std::to_string(normalNr++);
            }
            else if (name == "texture_height")
            {
                number = std::to_string(heightNr++);
            }

            glUniform1i(glGetUniformLocation(shader.ID, (name + number).c_str()), i);

            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }
        //매쉬 그리기
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        
        //VAO 해제
        glBindVertexArray(0);
        //초기화
        glActiveTexture(GL_TEXTURE0);
    }

private:
    unsigned int VBO, EBO;

    void setupMesh()
    {
        //생성 Generator
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        
        glBindVertexArray(VAO);
        //정점 버퍼 바인딩
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        //인덱스 바인딩
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
        
        //정점 설정

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        glEnableVertexAttribArray(1);
        
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));
        glEnableVertexAttribArray(3);

        glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));
        glEnableVertexAttribArray(4);

            glVertexAttribPointer(5,4, GL_INT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));
            glEnableVertexAttribArray(5);

            glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
            glEnableVertexAttribArray(6);
        //VAO 해제
        glBindVertexArray(0);
    }
};
