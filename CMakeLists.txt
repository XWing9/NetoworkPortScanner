cmake_minimum_required(VERSION 3.16)
project(NetworkPortScanner VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files (ImGui core + GLFW/OpenGL3 backends)
set(SOURCES
    main.cpp
    GUI/GUIManager.cpp
    GUI/GUIManager.h
    CoreLogic/CoreManager.cpp
    CoreLogic/CoreManager.h
    imGUI/frontend/imgui.cpp
    imGUI/frontend/imgui_draw.cpp
    imGUI/frontend/imgui_widgets.cpp
    imGUI/frontend/imgui_tables.cpp
    imGUI/frontend/imgui_demo.cpp
    imGUI/backend/imgui_impl_glfw.cpp
    imGUI/backend/imgui_impl_opengl3.cpp
)

# Fetch GLFW for window management (only external fetch allowed for backend compatibility)
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Create executable
add_executable(NetworkPortScanner ${SOURCES})

# Include directories
target_include_directories(NetworkPortScanner PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/imGUI/frontend
    ${CMAKE_CURRENT_SOURCE_DIR}/imGUI/backend
    ${CMAKE_CURRENT_SOURCE_DIR}/GUI
    ${CMAKE_CURRENT_SOURCE_DIR}/CoreLogic
)

# Link libraries
target_link_libraries(NetworkPortScanner PRIVATE
    glfw
    OpenGL::GL
)

# Use the native Win32 system libraries if needed
if (WIN32)
    target_link_libraries(NetworkPortScanner PRIVATE user32 gdi32 shell32)
endif()
