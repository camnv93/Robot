//
// Created by Dev on 23/02/2023.
//

#include "Grid.h"
Grid::Grid(int size)
: size_(size) {
  this->grid_.resize(size, std::vector<char>(size, DEF_LINE));
}

void Grid::SetPoint(const Coordinates &coor, const char &value) {
  this->grid_[coor.x][coor.y] = value;
}
matrix Grid::GetMatrix() const {
  return this->grid_;
}
int Grid::GetSize() const {
  return this->size_;
}
