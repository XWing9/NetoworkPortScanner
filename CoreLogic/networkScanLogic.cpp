#include "networkScanLogic.h"

NetworkScanLogic::NetworkScanLogic(AppState& state) : state(state) {}

void NetworkScanLogic::startScan() {
    if (state.isScanning) return;

    state.clearResults();           // replaces openPorts.clear()

    std::thread scanThread([this]() {
        scanNetwork();
    });
    scanThread.detach();
}

void NetworkScanLogic::stopScan() {
    state.isScanning = false;
}

void NetworkScanLogic::scanNetwork() {
    state.isScanning = true;
    state.statusText = "Scanning...";

    std::string localIP = getLocalIP();

    // your original port list, unchanged
    std::vector<int> commonPorts = {
        20, 21, 22, 23, 25, 53, 80, 110, 143, 443, 465, 587,
        993, 995, 3306, 3389, 5432, 5900, 8080, 8443, 27017, 5000
    };

    for (int port : commonPorts) {
        if (!state.isScanning) break;

        // same as before, just pushed to AppState instead of openPorts
        ScanResult info;
        info.ip      = localIP;
        info.port    = port;
        info.status  = "Closed";
        info.service = "unknown";

        // TODO: your actual port connection logic goes here
        // same place as before

        state.pushResult(info);
    }

    state.isScanning = false;
    state.statusText = "Done";
}

std::string NetworkScanLogic::getLocalIP() {
    #ifdef _WIN32
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            return "Error";
        }

        char hostname[256];
        gethostname(hostname, sizeof(hostname));

        struct hostent* host = gethostbyname(hostname);
        if (host != nullptr && host->h_addr_list[0] != nullptr) {
            return inet_ntoa(*(struct in_addr*)host->h_addr_list[0]);
        }
        WSACleanup();
    #else
        struct ifaddrs* ifaddr;
        if (getifaddrs(&ifaddr) == -1) return "Error";

        for (struct ifaddrs* ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
            if (ifa->ifa_addr != nullptr && ifa->ifa_addr->sa_family == AF_INET) {
                char ip[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &((struct sockaddr_in*)ifa->ifa_addr)->sin_addr, ip, INET_ADDRSTRLEN);
                if (std::string(ip) != "127.0.0.1") {
                    freeifaddrs(ifaddr);
                    return ip;
                }
            }
        }
        freeifaddrs(ifaddr);
    #endif

        return "127.0.0.1";
}