cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_CXX_STANDARD 17)

# 실행 파일 이름 설정
set(EXEC_NAME _OpenGL)

# 실행 파일 빌드 (소스 파일들 등록)
add_executable(${EXEC_NAME}
    main.cpp
    src/TextureLoader.cpp
    src/Skybox.cpp
)

include(Dependency.cmake)

# 패키지 찾기
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(ASSIMP REQUIRED assimp)
find_package(glm CONFIG REQUIRED)

# glad 라이브러리 빌드 (STATIC 라이브러리로 빌드함)
add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

# include 디렉토리 추가 (PRIVATE: 해당 타겟에만 영향)
target_include_directories(${EXEC_NAME}
    PRIVATE
        ${DEP_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/include
        ${GLFW_INCLUDE_DIRS}
        ${ASSIMP_INCLUDE_DIRS}
        /opt/homebrew/include
)

# 링크 디렉토리 설정 (라이브러리를 찾을 경로)
target_link_directories(${EXEC_NAME}
    PRIVATE
        ${DEP_LIB_DIR}
        /opt/homebrew/lib
)

# 라이브러리 링크
target_link_libraries(${EXEC_NAME}
    PRIVATE
        ${DEP_LIBS}
        glad
        ${GLFW_LIBRARIES}
        ${ASSIMP_LIBRARIES}
        "-framework OpenGL"
)
# 쉐이더 및 리소스 복사 (빌드 시 자동 복사됨)
file(COPY ${PROJECT_SOURCE_DIR}/shader    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_dependencies(${EXEC_NAME} ${DEP_LIST})