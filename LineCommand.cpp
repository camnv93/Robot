//
// Created by Dev on 24/02/2023.
//

#include "LineCommand.h"
void LineCommand::ExecuteCommand(Robot &robot) {
  robot.LineTo(this->coordinates_);
}

LineCommand::LineCommand()
    : coordinates_(0, 0) {

}
LineCommand::LineCommand(const Coordinates &coordinates)
    : coordinates_(coordinates) {

}
