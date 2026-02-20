#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include "../imGUI/frontend/imgui.h"
#include <GLFW/glfw3.h>

class GUIManager {
public:
    GUIManager();
    ~GUIManager();

    bool initialize(GLFWwindow* window);

    void newFrame();

    void render();

    void endFrame();

    void shutdown();

private:
    GLFWwindow* window;
    float clearColor[4];
};

#endif // GUIMANAGER_H