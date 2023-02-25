//
// Created by Dev on 23/02/2023.
//

#pragma once
#include "Grid.h"
#include "Coordinates.h"

class Robot {
 public:
  Robot();
  explicit Robot(Grid grid);
  void MoveTo(const Coordinates &des_coor);
  void LineTo(const Coordinates &des_coor);
  void Show();
 private:
  bool IsValidCorr(const Coordinates &coordinates);
  std::vector<Coordinates> FindStepByX(const Coordinates &des_coor) const;
  std::vector<Coordinates> FindStepByY(const Coordinates &des_coor) const;
  std::vector<Coordinates> FindStep(const Coordinates& des_coor) const;

  Grid grid_;
  Coordinates coordinates_;
};
