#include "GUIGeneration.h"
#include "../imGUI/backend/imgui_impl_glfw.h"
#include "../imGUI/backend/imgui_impl_opengl3.h"
#include <GL/gl.h>

GUIGeneration::GUIGeneration(){
    return;
}

void GUIGeneration::genTrackingWindow(){
    ImGui::Begin("Tracking Window");  // New window with the name "Tracking"
    ImGui::Text("Button clicked!");
    ImGui::End();
};

void GUIGeneration::genanotherWindow(float color1, float color2, float color3, float color4, GLFWwindow* window){
    ImGui::Begin("Welcome");
    ImGui::Text("Network Port Scanner is running!");
    ImGui::Separator();


}