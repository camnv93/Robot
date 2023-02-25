//
// Created by Dev on 23/02/2023.
//

#pragma once

#include <utility>

#include "Grid.h"
class ExportGrid {
 public:
  virtual ~ExportGrid() = default;
  virtual void Export() const = 0;
 protected:
  explicit ExportGrid(Grid grid)
      : grid_(std::move(grid)){
  }
  Grid grid_;
};

