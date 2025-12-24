#ifndef FILE_OBSERVER_H
#define FILE_OBSERVER_H

#include "observer.h"
#include <fstream>

class FileObserver : public Observer {
private:
    std::ofstream file;
public:
    FileObserver(const std::string& filename);
    ~FileObserver();
    void onKill(const std::string& killer, const std::string& victim) override;
};

#endif
