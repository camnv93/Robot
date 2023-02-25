//
// Created by Dev on 24/02/2023.
//

#pragma once
#include "Command.h"
class InitCommand : public Command {
 public:
  InitCommand();
  explicit InitCommand(int size);
  void ExecuteCommand(Robot &robot) override;
 private:
  int size_;
};
