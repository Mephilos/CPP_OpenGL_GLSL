#include "ObjectLayout.h"

namespace ObjectLayout
{
    const std::vector<glm::vec3>& DefaultLayout()
    {
        static std::vector<glm::vec3> layout = {
            {0.0f,  0.0f,  0.0f},
            {2.0f,  5.0f, -15.0f},
            {-1.5f, -2.2f, -2.5f},
            {-3.8f, -2.0f, -12.3f},
            {2.4f, -0.4f, -3.5f},
            {-1.7f, 3.0f, -7.5f},
            {1.3f, -2.0f, -2.5f},
            {1.5f, 2.0f, -2.5f},
            {1.5f, 0.2f, -1.5f},
            {-1.3f, 1.0f, -1.5f}
        };
        return layout;
    }
}