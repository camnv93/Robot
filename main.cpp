#include <iostream>
#include "ParserCommand.h"

int main() {
  Robot robot;
  std::string input_cmd;
  while (true) {
    std::getline(std::cin, input_cmd);
    if(input_cmd != "exit") {
      break;
    }
    ParserCommand parser_command(input_cmd);
    auto cmd = parser_command.GetCommandFromInput();
    cmd->ExecuteCommand(robot);
    robot.Show();
  }
  return 0;
}
