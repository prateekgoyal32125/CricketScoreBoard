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
  FieldingTeamRole(int numberOfPlayers) : TeamRole(numberOfPlayers) {
    extras = new Extras();
  }

  void displayScoreBoard() {}
};

#endif