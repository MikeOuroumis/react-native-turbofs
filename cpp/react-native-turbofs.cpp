#include "react-native-turbofs.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

namespace turbofs {

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::ostringstream content;
    content << file.rdbuf();
    file.close();

    return content.str();
}

std::vector<std::string> readDir(const std::string& dirPath) {
    std::vector<std::string> fileList;
    DIR* dir = opendir(dirPath.c_str());
    if (!dir) {
        throw std::runtime_error("Unable to open directory: " + dirPath);
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::string fileName = entry->d_name;

        // Skip special directories "." and ".."
        if (fileName == "." || fileName == "..") {
            continue;
        }

        fileList.push_back(dirPath + "/" + fileName);
    }

    closedir(dir);
    return fileList;
}

} // namespace turbofs
