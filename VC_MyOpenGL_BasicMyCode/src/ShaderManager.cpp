#include "ShaderManager.h"

std::unordered_map<std::string, std::unique_ptr<Shader>> ShaderManager::shaders;


void ShaderManager::LoadShader(const std:: string& name,
                               const std:: string& vertexPath,
                               const std:: string& fragmentPath)
{
    auto shader = std::make_unique<Shader>(vertexPath.c_str(), fragmentPath.c_str());

    shaders[name] = std::move(shader);
}

Shader& ShaderManager::GetShader(const std::string& name)
{
    if(shaders.find(name) == shaders.end())
    {
        std::cerr << "ShaderManager Error: " << name << '\n';
        std::exit(EXIT_FAILURE);
    }

    return *shaders[name];
}


void ShaderManager::Clear()
{
    shaders.clear();
}