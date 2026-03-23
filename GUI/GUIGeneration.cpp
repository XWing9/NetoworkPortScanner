#include "GUIGeneration.h"

#include <string>
#include <vector>
#include "../imGUI/backend/imgui_impl_opengl3.h"

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
    bool networkPortTrackingClicked = ImGui::Button("Track Network Ports");
    ImGui::Spacing();
    bool portTrackingClicked = ImGui::Button("Track own Ports");
    ImGui::End();

    return networkPortTrackingClicked;
}

void GUIGeneration::genTrackingCharts(int halfWindowWidthSize,int halfWindowHeightSize,
                                        const std::vector<ScanResult>& ports){
    ImGui::SetNextWindowPos(ImVec2(halfWindowWidthSize, 0));
    ImGui::SetNextWindowSize(ImVec2(halfWindowWidthSize + 400, halfWindowHeightSize));

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
    ImGui::Unindent();
    ImGui::Separator();
    ImGui::Spacing();
    genOpenPortTable(ports);
    ImGui::End();
}

void GUIGeneration::genOpenPortTable(const std::vector<ScanResult>& ports){
    struct PortInfo{ std::string portType;bool open;};

    if (ImGui::BeginTable("Ports", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_Resizable)){
        ImGui::TableSetupColumn("IP address");
        ImGui::TableSetupColumn("Port");
        ImGui::TableSetupColumn("Service");
        ImGui::TableSetupColumn("Status");
        ImGui::TableHeadersRow();

        for (const auto& port : ports)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", port.ip.c_str());

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%d", port.port);

            ImGui::TableSetColumnIndex(2);
            ImGui::Text("%s", port.service.c_str());

            ImGui::TableSetColumnIndex(3);
            ImGui::Text("%s", port.status.c_str());
        }

        ImGui::EndTable();
    }
}