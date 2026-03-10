#include "GUIGeneration.h"
#include "../imGUI/backend/imgui_impl_glfw.h"
#include "../imGUI/backend/imgui_impl_opengl3.h"
#include <GL/gl.h>

//constructor
GUIGeneration::GUIGeneration(){
    return;
}

bool GUIGeneration::genTrackingWindow(int halfWindowWidthSize,int windowHeight){
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(halfWindowWidthSize, windowHeight));

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
}

void GUIGeneration::genTrackingCharts(int halfWindowWidthSize,int halfWindowHeightSize){
    ImGui::SetNextWindowPos(ImVec2(halfWindowWidthSize, 0));
    ImGui::SetNextWindowSize(ImVec2(halfWindowWidthSize, halfWindowHeightSize));

    //der name in der methode is piepe, die referenz zum orginall zählt
    // er muss aber trotzdem denn name in der methode nutzen um es zu suchen
    //würde er es anstatt bestellung papier nennen wurde er papier. etc ....
    //suchen
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoMove        |  // Can't be dragged
        ImGuiWindowFlags_NoResize      |  // Can't be resized
        ImGuiWindowFlags_NoCollapse    |  // Can't be collapsed/hidden
        ImGuiWindowFlags_NoTitleBar;  // Removes title bar entirely


    ImGui::Begin("Charts Window",nullptr,flags);
    ImGui::Text("Tracking Charts");
    ImGui::End();
}