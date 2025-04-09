#pragma once

#include "Shader.h"
#include <unordered_map>
#include <memory>

class ShaderManager
{
public:
    static void LoadShader(const std::string& name,
                           const std::string& vertexPath,
                           const std::string& fragmentPath);
    static Shader& GetShader(const std::string& name);

    static void Clear();

private:
    ShaderManager() = delete;
    static std::unordered_map<std::string, std::unique_ptr<Shader>> shaders;
};
