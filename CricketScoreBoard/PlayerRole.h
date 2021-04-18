#ifndef PLAYERROLE_H
#define PLAYERROLE_H

#pragma once
#include <string>
#include <tuple>

class PlayerRole {
 public:
  virtual std::tuple<std::string, int, int, int, int> displayScoreBoard(
      std::string name) = 0;
};

#endif