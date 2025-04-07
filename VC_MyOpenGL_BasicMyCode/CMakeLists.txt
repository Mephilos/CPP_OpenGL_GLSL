cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_CXX_STANDARD 17)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(glm CONFIG REQUIRED)


include_directories(
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/glad/include
)
link_directories(${GLFW_LIBRARY_DIRS})

# GLAD (수동 추가)
add_library(glad STATIC glad/src/glad.c)

# 실행파일 
add_executable(Main_OpenGL
    main.cpp
    src/Camera.cpp
)

# 인클루드 디렉토리
target_include_directories(Main_OpenGL PRIVATE
    glad/include
    ${GLFW_INCLUDE_DIRS}
    /opt/homebrew/include  # macOS용 기본 include 경로
    ${CMAKE_SOURCE_DIR}/include
)

# 링크 라이브러리 지정
target_link_libraries(Main_OpenGL
    glad
    ${GLFW_LIBRARIES}
    "-framework OpenGL"
)
