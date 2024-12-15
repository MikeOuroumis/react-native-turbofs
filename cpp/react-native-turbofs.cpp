#include "react-native-turbofs.h"
#include <fstream>
#include <sstream>
#include <stdexcept>


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

}
