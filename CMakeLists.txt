cmake_minimum_required(VERSION 3.19)
project(PacMan)

set(CMAKE_CXX_STANDARD 14)

add_executable(PacMan main.cpp cmake-build-debug/Engine.h Engine.cpp Engine.h Moving.cpp Moving.h Player.cpp Player.h Gnome.cpp Gnome.h Traal.cpp Traal.h HighScore.cpp HighScore.h ScoreBoard.cpp ScoreBoard.h)