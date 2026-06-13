#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream meminfo("/proc/meminfo");
    if (!meminfo.is_open()) {
        std::cerr << "Failed to open /proc/meminfo\n";
        return 1;
    }

    std::string line;
    while (std::getline(meminfo, line)) {
        std::istringstream iss(line);
        std::string key, unit;
        long value;

        iss >> key >> value >> unit;
        key.pop_back(); // remove trailing ':'

        if (key == "MemTotal" || key == "MemFree" || key == "MemAvailable") {
            std::cout << key << ": " << value / 1024 << " MB\n";
        }
    }

    return 0;
}	