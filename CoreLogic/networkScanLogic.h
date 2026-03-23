#ifndef NETWORKPORTSCANNER_NETWORKSCANLOGIC_H
#define NETWORKPORTSCANNER_NETWORKSCANLOGIC_H

#include "../appState.h"
#include <thread>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <winsock2.h>
    #include <iphlpapi.h>
    #pragma comment(lib, "ws2_32.lib")
    #pragma comment(lib, "iphlpapi.lib")
#else
    #include <ifaddrs.h>
    #include <arpa/inet.h>
#endif

class NetworkScanLogic {
public:
    NetworkScanLogic(AppState& state);

    void startScan();   // replaces onStartTrackingPressed
    void stopScan();

private:
    void scanNetwork(); // same as before, now writes to AppState
    std::string getLocalIP();

    AppState& state;    // reference to shared state
};

#endif //NETWORKPORTSCANNER_NETWORKSCANLOGIC_H