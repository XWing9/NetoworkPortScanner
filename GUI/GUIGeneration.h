#ifndef NETWORKPORTSCANNER_GUIGENERATION_H
#define NETWORKPORTSCANNER_GUIGENERATION_H

#pragma once
#include "../appState.h"
#include <vector>

class GUIGeneration
{
    public:
        GUIGeneration();

        static bool genTrackingWindow(int windowWidth, int windowHeight);

        void genTrackingCharts(int halfWindowWidthSize, int halfWindowHeightSize,
                                        const std::vector<ScanResult>& ports);

        void generateTable();
    private:
        void genOpenPortTable(const std::vector<ScanResult>& ports);
};

#endif //NETWORKPORTSCANNER_GUIGENERATION_H