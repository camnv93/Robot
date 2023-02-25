//
// Created by Dev on 24/02/2023.
//

#pragma once
#include "Command.h"
#include "CommandType.h"

class ParserCommand {
 public:
  explicit ParserCommand(std::string cmd_str);
  std::shared_ptr<Command> GetCommandFromInput();

 private:
  static CommandType GetCommandType(const std::string &cmd);
  static std::shared_ptr<Command> GetExeCommand(std::vector<std::string> tokens);
  static std::vector<int> GetValuesFromInput(const std::string &input);
  std::string cmd_str_;
};
