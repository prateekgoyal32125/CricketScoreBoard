#ifndef TEAMROLE_H
#define TEAMROLE_H

#pragma once
#include <list>

#include "Player.h"

enum class TeamRoleEnum { BATTING, BOWLING, NONE };

class TeamRole {
 protected:
  std::list<Player *> playerList;

 public:
  TeamRole(std::list<Player *> &playerList) : playerList(playerList) {}
  virtual void displayScoreBoard() = 0;
  virtual void setPlayerList(std::list<Player *> &newPlayerList);
};

#endif
