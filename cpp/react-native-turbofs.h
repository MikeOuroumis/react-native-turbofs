#ifndef TURBOFS_H
#define TURBOFS_H

#include <string>
#include <vector>

namespace turbofs {
  std::string readFile(const std::string& filePath);
  std::vector<std::string> readDir(const std::string& dirPath);
}

#endif /* TURBOFS_H */
