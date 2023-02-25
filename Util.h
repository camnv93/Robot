//
// Created by Dev on 24/02/2023.
//

#pragma once
#include <string>
#include <vector>

class Util {
 public:
  static std::vector<std::string> SplitString(const std::string &input, const std::string &delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = input.find(delimiter, start)) != std::string::npos) {
      tokens.push_back(input.substr(start, end - start));
      start = end + 1;
    }
    tokens.push_back(input.substr(start));
    return tokens;
  }
};