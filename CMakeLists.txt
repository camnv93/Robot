cmake_minimum_required(VERSION 3.23)
project(RobotMove)

set(CMAKE_CXX_STANDARD 14)

add_executable(RobotMove main.cpp Coordinates.h Grid.cpp Grid.h ExportGrid.h Export2Console.cpp Export2Console.h Robot.cpp Robot.h Command.h MoveCommand.cpp MoveCommand.h LineCommand.cpp LineCommand.h InitCommand.cpp InitCommand.h ParserCommand.cpp ParserCommand.h CommandType.h Util.h)
