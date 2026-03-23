#ifndef COREMANAGER_H
#define COREMANAGER_H

#include "../appState.h"
#include "networkScanLogic.h"

class CoreManager {
    public:
        CoreManager(AppState& state);

        //called every frame from main loop to check event que?
        //why i have no fucking idea
        void update();

    private:
        AppState& state;

        NetworkScanLogic networkScanner; // why i do void here?
};

#endif // COREMANAGER_H
