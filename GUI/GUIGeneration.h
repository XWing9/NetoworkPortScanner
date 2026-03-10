#ifndef NETWORKPORTSCANNER_GUIGENERATION_H
#define NETWORKPORTSCANNER_GUIGENERATION_H
#include "imgui_impl_glfw.h"
#include "GLFW/glfw3.h"

class GUIGeneration
{
    public:
        GUIGeneration();

        static bool genTrackingWindow(int windowWidth, int windowHeight);

        void static genTrackingCharts(int halfWindowWidthSize, int halfWindowHeightSize);

        void generateTable();
};

#endif //NETWORKPORTSCANNER_GUIGENERATION_H