#include "GUIGeneration.h"

#include <string>
#include <vector>
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
    ImGui::Dummy(ImVec2(0, 20));
    ImGui::Indent();
    bool trackingClicked = ImGui::Button("Start tracking");
    ImGui::Text("window");
    ImGui::End();

    return trackingClicked;
}

void GUIGeneration::genTrackingCharts(int halfWindowWidthSize,int halfWindowHeightSize){
    ImGui::SetNextWindowPos(ImVec2(halfWindowWidthSize, 0));
    ImGui::SetNextWindowSize(ImVec2(halfWindowWidthSize, halfWindowHeightSize));

    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoMove        |  // Can't be dragged
        ImGuiWindowFlags_NoResize      |  // Can't be resized
        ImGuiWindowFlags_NoCollapse    |  // Can't be collapsed/hidden
        ImGuiWindowFlags_NoTitleBar;  // Removes title bar entirely

    ImGui::Begin("Charts Window",nullptr,flags);
    ImGui::Dummy(ImVec2(0, 20));
    ImGui::Indent(100.0f);
    ImGui::Text("Open Ports:");
    ImGui::Unindent();
    ImGui::Separator();
    ImGui::Spacing();
    genOpenPortTable();
    ImGui::End();
}

void GUIGeneration::genOpenPortTable(){
    struct PortInfo{ std::string portType;bool open;};
    //tmp table filler ig
    std::vector<PortInfo> ports = {
        {"HTTP",true},
        {"HTTPS",false}
    };

    if (ImGui::BeginTable("Ports", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable))
    {
        ImGui::TableSetupColumn("Port Type");
        ImGui::TableSetupColumn("Open");
        ImGui::TableHeadersRow();

        for (auto& port : ports)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0); ImGui::Text("%s", port.portType.c_str());
            ImGui::TableSetColumnIndex(1); ImGui::Text("%s", port.open ? "Yes" : "No");
        }

        ImGui::EndTable();
    }}