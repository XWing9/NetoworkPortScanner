#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "../imGUI/frontend/imgui.h"
#include "../CoreLogic/CoreManager.h"
#include <GLFW/glfw3.h>

#include "../GUI\GUIGeneration.h"
#include "../appState.h"

class GUIManager {
public:
    GUIManager(AppState& state);
    ~GUIManager();

    bool initialize(GLFWwindow* window);
    void newFrame();
    void render();
    void endFrame();
    void shutdown();

private:
    AppState& state;

    GLFWwindow* window;
    float clearColor[4];

    GUIGeneration GUIGen;
    bool showLabel = false;
};

#endif // GUIMANAGER_H