//
// Created by Dev on 24/02/2023.
//

#pragma once
#include "Command.h"
#include "Coordinates.h"
class MoveCommand : public Command {
 public:
  MoveCommand();
  explicit MoveCommand(const Coordinates &coordinates);
  void ExecuteCommand(Robot &robot) override;
 private:
  Coordinates coordinates_;
};
