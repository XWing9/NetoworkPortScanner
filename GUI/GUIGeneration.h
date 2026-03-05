#ifndef NETWORKPORTSCANNER_GUIGENERATION_H
#define NETWORKPORTSCANNER_GUIGENERATION_H
#include "imgui_impl_glfw.h"
#include "GLFW/glfw3.h"

class GUIGeneration
{
    public:
        GUIGeneration();

        bool genTrackingWindow(int windowWidth, int windowHeight);

        void genanotherWindow();

        void generateTable();
};

#endif //NETWORKPORTSCANNER_GUIGENERATION_H