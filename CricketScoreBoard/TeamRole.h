#ifndef TEAMROLE_H
#define TEAMROLE_H

#pragma once
#include <list>

#include "Player.h"

enum class TeamRoleEnum { BATTING, BOWLING, NONE };

class TeamRole {
 protected:
  int numberOfPlayers;
 public: 
  TeamRole(int numberOfPlayers) : numberOfPlayers(numberOfPlayers) {}
  virtual void displayScoreBoard() = 0;
  int getNumberOfPlayers();
};

#endif
