//
// Created by Dev on 23/02/2023.
//

#pragma once
#include <vector>
#include "Coordinates.h"

constexpr char DEF_LINE = '.';
using matrix = std::vector<std::vector<char>>;

class Grid {
 public:
  Grid() = default;
  explicit Grid(int size);

  void SetPoint(const Coordinates &coor, const char &value) ;

  matrix GetMatrix() const;

  int GetSize() const;
 private:
  int size_;
  matrix grid_;
};
