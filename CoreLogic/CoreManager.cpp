#include "CoreManager.h"

CoreManager::CoreManager() : statusText("Start Tracking") {}

std::string CoreManager::getStatusText() const {
    return statusText;
}