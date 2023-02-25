//
// Created by Dev on 24/02/2023.
//

#pragma once

#include "Robot.h"
#include "Coordinates.h"
class Command {
 public:
  virtual void ExecuteCommand(Robot &robot) = 0;
  virtual ~Command() = default;
 protected:
  Command() = default;
};