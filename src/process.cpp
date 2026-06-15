#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cctype>

using namespace std;

bool isNumber(const string& str) {
    if (str.empty())
        return false;

    for (unsigned char c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int main() {
    cout << "PID\tName\t\tMemory (VmRSS)\n";
    cout << "-------------------------------------\n";

    for (const auto& entry : filesystem::directory_iterator("/proc")) {
        string pid = entry.path().filename().string();

        if (!isNumber(pid))
            continue;

        string statusPath = std::string("/proc/") + pid + "/status";

        try {
            ifstream file(statusPath);

            if (!file)
                continue;

            string line;
            string name = "Unknown";
            string memory = "0 kB";

            while (getline(file, line)) {
                if (line.rfind("Name:", 0) == 0)
                    name = line.substr(6);
                else if (line.rfind("VmRSS:", 0) == 0)
                    memory = line.substr(7);
            }

            cout << pid << "\t" << name << "\t" << memory << "\n";
        }
        catch (const filesystem::filesystem_error& e) {
            continue;
        }
    }

    return 0;
}