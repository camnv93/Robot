//
// Created by Dev on 23/02/2023.
//

#include <iostream>
#include "Export2Console.h"

void Export2Console::Export() const {
  const auto grid_value = grid_.GetMatrix();
  auto size = grid_value.size();
  for (int y = 0; y < size; ++y) {
    for (int x = 0; x < size; ++x) {
      std::cout << grid_value[y][x];
    }
    std::cout << std::endl;
  }
}
Export2Console::Export2Console(const Grid &grid)
: ExportGrid(grid){

}

