#ifndef NETWORKPORTSCANNER_GUIGENERATION_H
#define NETWORKPORTSCANNER_GUIGENERATION_H
#include "imgui_impl_glfw.h"
#include "GLFW/glfw3.h"

class GUIGeneration
{
    public:
        GUIGeneration();

        void genTrackingWindow();

        void genanotherWindow();
        void genanotherWindow(float x, float x1, float x2, float x3, GLFWwindow* window);
};

#endif //NETWORKPORTSCANNER_GUIGENERATION_H