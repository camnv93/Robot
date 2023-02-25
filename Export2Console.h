//
// Created by Dev on 23/02/2023.
//

#pragma once

#include "ExportGrid.h"
class Export2Console : public ExportGrid {
 public:
  explicit Export2Console(const Grid &grid);
  void Export() const override;
};
