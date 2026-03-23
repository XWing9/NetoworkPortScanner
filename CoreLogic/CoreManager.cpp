#include "CoreManager.h"
#include <thread>

CoreManager::CoreManager(AppState& state) : state(state), networkScanner(state){}

void CoreManager::update(){
    UIEvent e;

    while (state.pollEvent(e)){
        switch (e){
        case UIEvent::startScan:
            networkScanner.startScan();
            break;

        case UIEvent::stopScan:
            networkScanner.stopScan();
            break;

        default:
            break;
        }
    }
}