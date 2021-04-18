#ifndef TEAMPROFILE_H
#define TEAMPROFILE_H

#pragma once

#include <string>

#include "Generic.h"
#include "Player.h"
#include "Variadic.h"

class TeamProfile {
 public:
  std::string name;
  /*
  time_t teamStarted;
  vector<Tournament> tournamentsWon*/

  TeamProfile(std::string name) : name(name) {}

  static TeamProfile *getTeam(std::string name);
};

#endif
