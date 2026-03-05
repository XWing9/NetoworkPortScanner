#ifndef COREMANAGER_H
#define COREMANAGER_H

#include <string>

class CoreManager {
    public:
        CoreManager();
        std::string getStatusText() const;

        void onStartTrackingPressed();

    private:
        std::string statusText;
};

#endif // COREMANAGER_H
