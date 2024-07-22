#include <iostream>
#include <ctime>

int main() {
    __time64_t rawtime;
    struct tm timeinfo;
    char buffer[64];

    // Get the current time
    _time64(&rawtime);

    // Convert to local time
    if (_localtime64_s(&timeinfo, &rawtime) != 0) {
        std::cerr << "Error converting to local time" << std::endl;
        return 1;
    }

    // Format time as a string
    if (strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo) == 0) {
        std::cerr << "Error formatting time" << std::endl;
        return 1;
    }

    // Print the formatted time
    std::cout << "Current local time: " << buffer << std::endl;

    return 0;
}
