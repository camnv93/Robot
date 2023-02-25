//
// Created by Dev on 24/02/2023.
//

#include "MoveCommand.h"
void MoveCommand::ExecuteCommand(Robot &robot) {
  robot.MoveTo(this->coordinates_);
}

MoveCommand::MoveCommand(const Coordinates &coordinates)
    : coordinates_(coordinates) {
}

MoveCommand::MoveCommand()
    : coordinates_(0, 0) {
}
