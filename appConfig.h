#ifndef NETWORKPORTSCANNER_APPCONFIG_H
#define NETWORKPORTSCANNER_APPCONFIG_H

namespace appConfig{
    namespace windowSizes{
        inline constexpr int windowWidth = 1280;
        inline constexpr int windowHeight = 720;
        inline constexpr int halfWindowWidthSize = windowWidth / 2;
        inline constexpr int halfWindowHeightSize = windowHeight / 2;
    }

    namespace windowLabels{
        inline constexpr auto appName = "Network Port Scanner";
    }

    namespace windowColorSettings{
        //hower you define color in c++?
        inline constexpr float backgroundColor[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    }
}

#endif //NETWORKPORTSCANNER_APPCONFIG_H