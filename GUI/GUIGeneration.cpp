#include "GUIGeneration.h"
#include "../imGUI/backend/imgui_impl_glfw.h"
#include "../imGUI/backend/imgui_impl_opengl3.h"
#include <GL/gl.h>

//constructor
GUIGeneration::GUIGeneration(){
    return;
}

bool GUIGeneration::genTrackingWindow(int windowWidth,int windowHeight){
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(windowWidth * 0.5, 100));

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoMove        |  // Can't be dragged
        ImGuiWindowFlags_NoResize      |  // Can't be resized
        ImGuiWindowFlags_NoCollapse    |  // Can't be collapsed/hidden
        ImGuiWindowFlags_NoTitleBar;  // Removes title bar entirely

    ImGui::Begin("Tracking Window",nullptr,flags);
    bool trackingClicked = ImGui::Button("Start tracking");
    ImGui::Text("window");
    ImGui::End();

    return trackingClicked;
};

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