#include "CoreManager.h"
#include <iostream>
#include <thread>
#include <chrono>

#ifdef _WIN32
    #include <winsock2.h>
    #include <iphlpapi.h>
    #pragma comment(lib, "ws2_32.lib")
    #pragma comment(lib, "iphlpapi.lib")
#else
    #include <ifaddrs.h>
    #include <arpa/inet.h>
#endif

std::string CoreManager::getLocalIP() {
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
    
CoreManager::CoreManager() : statusText("Start Tracking"){}

std::string CoreManager::getStatusText() const {
    return statusText;
}

void CoreManager::scanNetwork() {
    statusText = "Scanning...";
    openPorts.clear();

    std::string localIP = getLocalIP();
    
    // Scan common ports (you can expand this range)
    std::vector<int> commonPorts = {
        20, 21, 22, 23, 25, 53, 80, 110, 143, 443, 465, 587, 
        993, 995, 3306, 3389, 5432, 5900, 8080, 8443, 27017, 5000
    };

    for (int port : commonPorts) {
        // Attempt to connect to each port
        PortInfo info;
        info.ip = localIP;
        info.port = port;
        info.status = "Closed";
        
        // TODO: Implement actual port connection logic
        // For now, you can add placeholder logic
        
        openPorts.push_back(info);
    }

    statusText = "Tracking";
}

void CoreManager::onStartTrackingPressed(){
    // Run scanning in a background thread to avoid freezing the UI
    std::thread scanThread([this]() {
        scanNetwork();
    });
    scanThread.detach();
}

const std::vector<PortInfo>& CoreManager::getOpenPorts() const {
    return openPorts;
}