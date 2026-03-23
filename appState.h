#ifndef NETWORKPORTSCANNER_APPSTATE_H
#define NETWORKPORTSCANNER_APPSTATE_H

#pragma once
#include <atomic>
#include <mutex>
#include <queue>
#include <vector>
#include <string>

//where stands what status im in?
enum class UIEvent{
    startScan,
    stopScan,
};

//ie port info
struct ScanResult{
    std::string ip;
    int port;
    std::string service;
    std::string status;
};

struct AppState{
    // --- Event queue (GUI -> Logic) ---
    std::mutex          eventMutex;
    std::queue<UIEvent> eventQueue;

    void pushEvent(UIEvent e) {
        std::lock_guard<std::mutex> lock(eventMutex);
        eventQueue.push(e);
    }

    bool pollEvent(UIEvent& out) {
        std::lock_guard<std::mutex> lock(eventMutex);
        if (eventQueue.empty()) return false;
        out = eventQueue.front();
        eventQueue.pop();
        return true;
    }

    // --- Scan state (Logic -> GUI) ---
    std::atomic<bool>   isScanning   = false;

    std::string statusText = "Ready";

    // --- Results (Logic -> GUI, thread-safe) ---
    std::mutex              resultsMutex;
    std::vector<ScanResult> scanResults;

    void pushResult(const ScanResult& r) {
        std::lock_guard<std::mutex> lock(resultsMutex);
        scanResults.push_back(r);
    }

    void clearResults() {
        std::lock_guard<std::mutex> lock(resultsMutex);
        scanResults.clear();
    }
};
#endif //NETWORKPORTSCANNER_APPSTATE_H