#ifndef COREMANAGER_H
#define COREMANAGER_H

#include <string>
#include <vector>
#include <map>

struct PortInfo {
    std::string ip;
    std::string service;
    std::string status;
    int port;
};

class CoreManager {
    public:
        CoreManager();
        std::string getStatusText() const;

        void onStartTrackingPressed();

        //network etection
        std::string getLocalIP();
        void scanNetwork();
        const std::vector<PortInfo>& getOpenPorts() const;

    private:
        std::string statusText;

        std::vector<PortInfo> openPorts;
};

#endif // COREMANAGER_H
