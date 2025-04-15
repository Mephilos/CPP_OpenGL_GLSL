#pragma once


#include "Shader.h"
#include "Mesh.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <map>
#include <vector>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model
{
public:
    std::vector<Texture> textures_loaded;
    std::vector<Mesh> meshes;
    std::string directory;
    bool gammaCorrection;

    //생성자 
    Model(std::string const &path, bool gamma = false) : gammaCorrection(gamma)
    {
        loadModel(path);
    }
    //셰이더 받아와서 그리기
    void Draw(Shader &shader)
    {
        for(unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].Draw(shader);
    }
private:
    // 모델 파일 로드
    void loadModel(std::string const &path)
    {
        Assimp::Importer importer;
        //경로, 비트마스크로 후처리 플래그 받음.
        //모델 삼각형으로 변환 : 노멀이 없으면 노멀 자동 생성 : OpenGL 좌표계 기준으로 UV뒤집음 : NormalMapping용 tangent, bitangent, normal
        const aiScene* scene = importer.ReadFile(path, 
            aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
        //read 가 안되거나, scene에 필요한 플레그가 덜 켜진 경우나 루트노드(구조)가 없는경우
        if(!scene || scene -> mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene -> mRootNode)
        {
            // assimp 전용 에러 메시지
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
            return;
        }

        directory = path.substr(0, path.find_last_of('/'));
        processNode(scene -> mRootNode, scene);
    }
    //노드 순회 (재귀...) 
    void processNode(aiNode *node, const aiScene *scene)
    {
        for(unsigned int i = 0; i < node -> mNumMeshes; i++)
        {
            aiMesh* mesh = scene -> mMeshes[node -> mMeshes[i]];
            //노드에서 매쉬 추출
            meshes.push_back(processMesh(mesh, scene));
        }
        for(unsigned int i = 0; i < node -> mNumChildren; i++)
        {
            //재귀
            processNode(node -> mChildren[i], scene);
        }
    }
    // 메쉬 변환
    Mesh processMesh(aiMesh *mesh, const aiScene *scene)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        

        //메쉬가 가지고 있는 정점 수만큼 반복
        for(unsigned int i = 0; i < mesh -> mNumVertices; i++)
        {
            Vertex vertex; 
            glm::vec3 vector; 

            //위치 저장 glm::vec3 vertor를 Vertex 구조체에 저장
            vector.x = mesh -> mVertices[i].x;
            vector.y = mesh -> mVertices[i].y;
            vector.z = mesh -> mVertices[i].z;
            vertex.Position = vector;

            //노멀 백터 저장 조명 계산용 glm::vec3 vertor를 Vertex 구조체에 저장
            if(mesh -> HasNormals())
            {
                vector.x = mesh -> mNormals[i].x;
                vector.y = mesh -> mNormals[i].y;
                vector.z = mesh -> mNormals[i].z;
                vertex.Normal = vector;
            }

            // 텍스처 좌표 + 탄젠트 비트탄젠트 저장
            if(mesh -> mTextureCoords[0])
            {
                glm::vec2 vec;
                vec.x = mesh -> mTextureCoords[0][i].x;
                vec.y = mesh -> mTextureCoords[0][i].y;
                vertex.TexCoords = vec;

                vector.x = mesh -> mTangents[i].x;
                vector.y = mesh -> mTangents[i].y;
                vector.z = mesh -> mTangents[i].z;
                vertex.Tangent = vector;

                vector.x = mesh -> mBitangents[i].x;
                vector.y = mesh -> mBitangents[i].y;
                vector.z = mesh -> mBitangents[i].z;
                vertex.Bitangent = vector;
            }
            else
            {
                //텍스처 없을 경우 기본값
                vertex.TexCoords = glm::vec2(0.0f, 0.0f);
            }
            //정점 리스트에 추가
            vertices.push_back(vertex);
        }

        //인덱스 파싱
        for(unsigned int i = 0; i < mesh -> mNumFaces; i++)
        {
            aiFace face = mesh -> mFaces[i];

            for(unsigned int j = 0; j < face.mNumIndices; j++)
            {
                indices.push_back(face.mIndices[j]); //면을 구성하는 인덱스추가
            }
        }

        // 머테리얼 에서 텍스처 추출
        aiMaterial* material = scene ->mMaterials[mesh -> mMaterialIndex];

        std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

        std::vector<Texture> normalMaps = loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
        textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

        std::vector<Texture> heightMaps = loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
        textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
        
        // 메쉬 클래스 객체로 만들어서 반환
        return Mesh(vertices, indices, textures);
    }

    // checks all material textures of a given type and loads the textures if they're not loaded yet.
    // the required info is returned as a Texture struct.
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName)
    {
        std::vector<Texture> textures;
    
        for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);
            //로딩 된 텍스처인지 확인 하는 플래그
            bool skip = false;

            //중복텍스처가 있는지 확인
            for(unsigned int j = 0; j < textures_loaded.size(); j++)
            {
                if(std::strcmp(textures_loaded[j].path.data(), str.C_Str()) == 0)
                {
                    //이미 로드된 텍스처면 재사용
                    textures.push_back(textures_loaded[j]);
                    skip = true;
                    break;
                }
            }
            //새로운 텍스처인 경우 실행
            if(!skip)
            {   
                Texture texture;
                texture.id = TextureFromFile(str.C_Str(), this->directory); //OpenGL텍스처 생성
                texture.type = typeName; //이름
                texture.path = str.C_Str(); //텍스처 파일경로 저장

                textures.push_back(texture); //이번 실행용으로 추가
                textures_loaded.push_back(texture);  //전체 모델용 캐시에도 추가(중복 방지)
            }
        }
        return textures;
    }
};

//stb_image.h 텍스처 바인딩 함수
unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma)
{
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}
