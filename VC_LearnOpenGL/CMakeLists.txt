cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(ASSIMP REQUIRED assimp)
find_package(glm CONFIG REQUIRED)

link_directories(/opt/homebrew/lib)

# GLAD (수동 추가)
add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)


include_directories(
    ${PROJECT_SOURCE_DIR}/include
)
file(COPY ${CMAKE_SOURCE_DIR}/shader DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
set(EXEC_NAME _OpenGL)

add_executable(${EXEC_NAME}
    src/Mesh.cpp
    src/stb_image.cpp
)
target_include_directories(${EXEC_NAME} PRIVATE
    ${GLFW_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIRS}
    /opt/homebrew/include
)

target_link_libraries(${EXEC_NAME}
    glad
    ${GLFW_LIBRARIES}
    ${ASSIMP_LIBRARIES}
    "-framework OpenGL"
)
