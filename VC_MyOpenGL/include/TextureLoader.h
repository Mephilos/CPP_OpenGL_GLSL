#pragma once

#include <glad/glad.h>
#include <string>
#include <vector>

class TextureLoader
{
public:
    static unsigned int LoadTexture2D(const std::string& path, bool flip = true, int wrap = GL_REPEAT);

    static unsigned int LoadCubemap(const std::vector<std::string>& faces);
};