#include "GUIManager.h"

GUIManager::GUIManager() {}

GUIManager::~GUIManager() {}

void GUIManager::render() {
    ImGui::Begin("Network Port Scanner");
    ImGui::Text("Welcome to the Network Port Scanner.");
    if (ImGui::Button("Start Scan")) {
        // Logic for starting a scan
    }
    ImGui::End();
}
