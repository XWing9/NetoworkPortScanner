#include "GUIManager.h"
#include "../imGUI/backend/imgui_impl_glfw.h"
#include "../imGUI/backend/imgui_impl_opengl3.h"
#include <iostream>
#include <GL/gl.h>

GUIManager::GUIManager() : window(nullptr) {
    clearColor[0] = 0.2f;
    clearColor[1] = 0.3f;
    clearColor[2] = 0.3f;
    clearColor[3] = 1.0f;
}

GUIManager::~GUIManager() {
    shutdown();
}

bool GUIManager::initialize(GLFWwindow* win) {
    window = win;

    if (!window) {
        std::cerr << "Invalid window passed to GUIManager" << std::endl;
        return false;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    return true;
}

void GUIManager::newFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

//main part where GUI is defined
void GUIManager::render() {
    // Main window
    ImGui::Begin("Welcome");
    ImGui::Text("Network Port Scanner is running!");
    ImGui::Separator();

    //GUIGen.genanotherWindow(clearColor[0], clearColor[1], clearColor[2], clearColor[3],window);

    ImGui::ColorEdit4("Clear Color", clearColor);

    if (ImGui::Button("Quit")) {
        glfwSetWindowShouldClose(window, true);
    }

    ImGui::Separator();
    ImGui::End();  // Close the original window

    GUIGen.genTrackingWindow();
}

void GUIManager::endFrame() {
    ImGui::Render();

    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);

    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}

void GUIManager::shutdown() {
    if (window) {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}
