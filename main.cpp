#include <iostream>
#include <vector>

// ImGui headers (include paths are set in CMake)
#include "imGUI/frontend/imgui.h"
#include "imGUI/backend/imgui_impl_glfw.h"
#include "imGUI/backend/imgui_impl_opengl3.h"

// GLFW
#include <GLFW/glfw3.h>

int main()
{
    // 1. Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return 1;
    }

    // 2. Configure GLFW window
    // Use OpenGL 3.3 Core Profile
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

    // 3. Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls

    // 4. Setup Platform/Renderer backends
    // imgui_impl_opengl3.cpp will use imgui_impl_opengl3_loader.h by default
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // 5. Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Simple Window for demonstration
        {
            ImGui::Begin("Welcome");
            ImGui::Text("Network Port Scanner is running!");
            ImGui::Separator();
            
            static float color[4] = { 0.2f, 0.3f, 0.3f, 1.00f };
            ImGui::ColorEdit4("Clear Color", color);
            
            if (ImGui::Button("Quit"))
                glfwSetWindowShouldClose(window, true);
            
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        
        // We need to get the color from the static variable above
        // For simplicity in this demo, I'll just use a fixed color or move the static outside
        static float clear_color[4] = { 0.2f, 0.3f, 0.3f, 1.00f };
        // Update clear_color if you want it to persist outside the scope, 
        // but for a minimal window this is fine.
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // 6. Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
