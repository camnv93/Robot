//
// Created by Dev on 24/02/2023.
//

#include "InitCommand.h"
InitCommand::InitCommand(int size)
    : size_(size) {
}

void InitCommand::ExecuteCommand(Robot &robot) {
  robot = Robot(Grid(this->size_));
}

InitCommand::InitCommand()
    : size_(0) {
}
