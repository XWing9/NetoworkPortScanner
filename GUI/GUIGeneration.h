#ifndef NETWORKPORTSCANNER_GUIGENERATION_H
#define NETWORKPORTSCANNER_GUIGENERATION_H
#include "imgui_impl_glfw.h"
#include "GLFW/glfw3.h"
#include <vector>

//change to give dynamiccly from GUIManager class not like this
#include "../CoreLogic/CoreManager.h"

class GUIGeneration
{
    public:
        GUIGeneration();

        static bool genTrackingWindow(int windowWidth, int windowHeight);

        static void genOpenPortTable(const std::vector<PortInfo>& ports);

        void static genTrackingCharts(int halfWindowWidthSize, int halfWindowHeightSize,const std::vector<PortInfo>& ports);

        void generateTable();
};

#endif //NETWORKPORTSCANNER_GUIGENERATION_H