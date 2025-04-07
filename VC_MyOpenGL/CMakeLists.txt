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


# src 디렉토리 안의 모든 .cpp 파일을 각각 실행파일로 빌드
file(GLOB SOURCES "src/*.cpp")



#명시적으로 추가 하는 방식
#add_executable(
#   HelloTriangle_OpenGL 
#    src/HelloTriangle.cpp
#    )
#target_link_libraries(
#    HelloTriangle_OpenGL 
#    glad 
#    ${GLFW_LIBRARIES} 
#    "-framework OpenGL"
#    )


foreach(source ${SOURCES})
    get_filename_component(FILENAME ${source} NAME_WE)
    
    if(FILENAME MATCHES "skip")
        message(STATUS "skipping ${FILENAME}")
        continue()
    endif()
    
    set(EXEC_NAME "${FILENAME}_OpenGL")

    add_executable(${EXEC_NAME} ${source} glad/src/glad.c)

    target_include_directories(${EXEC_NAME} PRIVATE
        glad/include
        ${GLFW_INCLUDE_DIRS}
        /opt/homebrew/include
    )

    target_link_libraries(${EXEC_NAME}
        glad
        ${GLFW_LIBRARIES}
        "-framework OpenGL"
    )
endforeach()