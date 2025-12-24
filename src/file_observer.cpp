#include "file_observer.h"

FileObserver::FileObserver(const std::string& filename) {
    file.open(filename, std::ios::app);
}

FileObserver::~FileObserver() {
    if (file.is_open()) file.close();
}

void FileObserver::onKill(const std::string& killer, const std::string& victim) {
    if (file.is_open()) {
        file << "[FILE] " << killer << " killed " << victim << std::endl;
    }
}
