//
// Created by Dev on 24/02/2023.
//

#include "ParserCommand.h"
#include "MoveCommand.h"
#include "LineCommand.h"
#include "InitCommand.h"
#include "Util.h"
#include <utility>

ParserCommand::ParserCommand(std::string cmd_str)
    : cmd_str_(std::move(cmd_str)) {
}

std::shared_ptr<Command> ParserCommand::GetCommandFromInput() {
  auto tokens = Util::SplitString(this->cmd_str_, " ");
  return GetExeCommand(tokens);
}

CommandType ParserCommand::GetCommandType(const std::string &cmd) {
  if (cmd == "DIMENSION") {
    return CommandType::DIMENSION;
  } else if (cmd == "MOVE_TO") {
    return CommandType::MOVE_TO;
  } else if (cmd == "LINE_TO") {
    return CommandType::LINE_TO;
  } else {
    return CommandType::UNDEFINED;
  }
}

std::shared_ptr<Command> ParserCommand::GetExeCommand(std::vector<std::string> tokens) {
  if (tokens.size() != 2) {
    throw std::invalid_argument("Invalid Command");
  }
  std::shared_ptr<Command> command;
  auto cmd_type = GetCommandType(tokens.at(0));
  auto cmd_values = GetValuesFromInput(tokens.at(1));
  switch (cmd_type) {
    case CommandType::DIMENSION:command = std::make_shared<InitCommand>(cmd_values.at(0));
      break;
    case CommandType::MOVE_TO:command = std::make_shared<MoveCommand>(Coordinates(cmd_values.at(0), cmd_values.at(1)));
      break;
    case CommandType::LINE_TO:command = std::make_shared<LineCommand>(Coordinates(cmd_values.at(0), cmd_values.at(1)));
      break;
    default:
      throw std::invalid_argument("Command not found!");
  }
  return command;
}

std::vector<int> ParserCommand::GetValuesFromInput(const std::string &input) {
  std::vector<int> values;
  auto str_values = Util::SplitString(input, ",");
  for(const auto& str : str_values) {
    values.push_back(std::stoi(str));
  }
  return values;
}

