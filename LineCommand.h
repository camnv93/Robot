//
// Created by Dev on 24/02/2023.
//

#pragma once
#include "Command.h"
class LineCommand : public Command {
 public:
  LineCommand();
  explicit LineCommand(const Coordinates &coordinates);
  void ExecuteCommand(Robot &robot) override;
 private:
  Coordinates coordinates_;
};
