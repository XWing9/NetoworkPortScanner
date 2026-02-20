#include <iostream>
#include <GLFW/glfw3.h>
#include "GUI/GUIManager.h"

int main()
{
    // 1. Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return 1;
    }

    // 2. Configure GLFW window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Network Port Scanner", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable VSync

    // 3. Create and initialize GUIManager
    GUIManager guiManager;
    if (!guiManager.initialize(window))
    {
        std::cerr << "Failed to initialize GUIManager" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // 4. Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Use GUIManager for all GUI operations
        guiManager.newFrame();
        guiManager.render();
        guiManager.endFrame();
    }

    // 5. Cleanup (GUIManager destructor handles ImGui cleanup)
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}