#include "GUIGeneration.h"
#include "../imGUI/backend/imgui_impl_glfw.h"
#include "../imGUI/backend/imgui_impl_opengl3.h"
#include <GL/gl.h>

//constructor
GUIGeneration::GUIGeneration(){
    return;
}

void GUIGeneration::genTrackingWindow(){
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(200, 100));

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoMove        |  // Can't be dragged
        ImGuiWindowFlags_NoResize      |  // Can't be resized
        ImGuiWindowFlags_NoCollapse    |  // Can't be collapsed/hidden
        ImGuiWindowFlags_NoTitleBar;  // Removes title bar entirely

    ImGui::Begin("Tracking Window",nullptr,flags);  // New window with the name "Tracking"
    ImGui::Text("window");
    ImGui::End();
};

void GUIGeneration::genanotherWindow(float color1, float color2, float color3, float color4, GLFWwindow* window){
    ImGui::Begin("Welcome");
    ImGui::Text("Network Port Scanner is running!");
    ImGui::Separator();
}

void GUIGeneration::generateTable()
{
    if (ImGui::BeginTable("test Table",2))
    {
        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Name");

        ImGui::TableSetColumnIndex(1);
        ImGui::InputText("##name","test", 64);

        ImGui::EndTable();
    }
}