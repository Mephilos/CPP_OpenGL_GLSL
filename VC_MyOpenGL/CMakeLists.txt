cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_CXX_STANDARD 17)

# 실행 파일 이름
set(EXEC_NAME _OpenGL)

# 소스 등록
add_executable(${EXEC_NAME}
    main.cpp
    src/TextureLoader.cpp
    src/Skybox.cpp
)

# 외부 의존성 처리
include(Dependency.cmake)

# 패키지 설정
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(ASSIMP REQUIRED assimp)
find_package(glm CONFIG REQUIRED)

# glad 라이브러리 (STATIC)
add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

# ImGui 라이브러리 (STATIC)
add_library(imgui STATIC
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_impl_glfw.cpp
    imgui/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    ${PROJECT_SOURCE_DIR}/imgui
    ${PROJECT_SOURCE_DIR}/glad/include
    ${GLFW_INCLUDE_DIRS}
)

target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)

# 실행 타겟 인클루드 설정
target_include_directories(${EXEC_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/imgui
        ${DEP_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
        ${ASSIMP_INCLUDE_DIRS}
        /opt/homebrew/include
)

# 링크 디렉토리
target_link_directories(${EXEC_NAME}
    PRIVATE
        ${DEP_LIB_DIR}
        /opt/homebrew/lib
)

# 링크 라이브러리
target_link_libraries(${EXEC_NAME}
    PRIVATE
        imgui
        glad
        ${GLFW_LIBRARIES}
        ${ASSIMP_LIBRARIES}
        ${DEP_LIBS}
        "-framework OpenGL"
)

# 리소스 복사
file(COPY ${PROJECT_SOURCE_DIR}/shader    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# 외부 프로젝트 빌드 의존성 추가
add_dependencies(${EXEC_NAME} ${DEP_LIST})