#ifndef FIELDINGTEAMROLE_H
#define FIELDINGTEAMROLE_H

#pragma once

#include "TeamRole.h"

struct Extras {};

class FieldingTeamRole : public TeamRole {
 protected:
  int oversBowled;
  int wicketsTaken;
  Extras *extras;

 public:
  FieldingTeamRole(std::list<Player *> &playerList)
      : TeamRole(playerList), oversBowled(0), wicketsTaken(0) {
    extras = new Extras();
  }

  void displayScoreBoard() {}
};

#endif