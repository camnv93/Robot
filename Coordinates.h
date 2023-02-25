//
// Created by Dev on 23/02/2023.
//

#pragma once
#include <iostream>

class Coordinates {
 public:
  Coordinates()
      : x(0),
        y(0) {
  }
  explicit Coordinates(int x, int y)
      : x(x),
        y(y) {
  }

  Coordinates operator-(const Coordinates &other ) const {
    return Coordinates(this->x - other.x, this->y - other.y);
  }

  Coordinates operator+(const Coordinates &other) const {
    return Coordinates(this->x + other.x, this->y + other.y);
  }
  int x;
  int y;
};
