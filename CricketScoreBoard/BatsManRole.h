#ifndef BATSMANROLE_H
#define BATSMANROLE_H

#include <ctime>
#include <list>
#include <map>
#include <tuple>

#include "Events.h"
#include "Generic.h"
#include "PlayerProfile.h"
#include "PlayerRole.h"

#pragma once

class BatsmanRole : public PlayerRole {
 protected:
  int score;
  int ballsFaced;
  Boundary boundary = Boundary();
  BatsManStatus status;

 public:
  BatsmanRole()
      : score(0),
        // isOnStrike(isOnStrike),
        ballsFaced(0),
        status(BatsManStatus::YET_TO_BAT) {}

  void setStatus(BatsManStatus newStatus);
  BatsManStatus getStatus();

  void incrementScore(RunAction *run);

  std::tuple<std::string, int, int, int, int> displayScoreBoard(
      std::string name);
};

#endif