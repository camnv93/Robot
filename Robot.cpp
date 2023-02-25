//
// Created by Dev on 23/02/2023.
//

#include <utility>
#include <memory>
#include "Robot.h"
#include "ExportGrid.h"
#include "Export2Console.h"

Robot::Robot(Grid grid)
    : grid_(std::move(grid)),
      coordinates_(Coordinates(0, 0)) {
  grid_.SetPoint(coordinates_, '+');
}

Robot::Robot()
    : grid_(0) {
}

void Robot::MoveTo(const Coordinates &des_coor) {
  if (!IsValidCorr(des_coor)) {
    throw std::invalid_argument("outside the grid des_coor");
  }
  this->coordinates_ = des_coor;
  grid_.SetPoint(coordinates_, '+');
}

void Robot::LineTo(const Coordinates &des_coor) {
  if (!IsValidCorr(des_coor)) {
    throw std::invalid_argument("outside the grid des_coor");
  }
  auto steps = FindStep(des_coor);
  for (const auto &step : steps) {
    grid_.SetPoint(step, '+');
  }
}

bool Robot::IsValidCorr(const Coordinates &coordinates) {
  if (coordinates.x >= this->grid_.GetSize() || coordinates.y >= this->grid_.GetSize()) {
    return false;
  }
  return true;
}

std::vector<Coordinates> Robot::FindStepByX(const Coordinates &des_coor) const {
  std::vector<Coordinates> steps;
  auto start = this->coordinates_.x;
  auto end = des_coor.x;
  auto step_move = (start < end) ? 1 : -1;
  while (start != end) {
    start += step_move;
    steps.emplace_back(Coordinates(start, this->coordinates_.y));
  }
  return steps;
}

std::vector<Coordinates> Robot::FindStepByY(const Coordinates &des_coor) const {
  std::vector<Coordinates> steps;
  auto start = this->coordinates_.y;
  auto end = des_coor.y;
  auto step_move = (start < end) ? 1 : -1;
  while (start != end) {
    start += step_move;
    steps.emplace_back(Coordinates(des_coor.x, start));
  }
  return steps;
}
std::vector<Coordinates> Robot::FindStep(const Coordinates &des_coor) const {
  std::vector<Coordinates> steps;
  auto steps_by_x = FindStepByX(des_coor);
  auto steps_by_y = FindStepByY(des_coor);
  steps.insert(steps.end(), steps_by_x.begin(), steps_by_x.end());
  steps.insert(steps.end(), steps_by_y.begin(), steps_by_y.end());
  return steps;
}
void Robot::Show() {
  std::unique_ptr<ExportGrid> export_grid = std::make_unique<Export2Console>(this->grid_);
  export_grid->Export();
}

