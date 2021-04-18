#ifndef BATTINGTEAMROLE_H
#define BATTINGTEAMROLE_H

#pragma once

#include <string>

#include "TeamRole.h"

class BattingTeamRole : public TeamRole {
 protected:
  int score;
  int bowlsBowled;
  int wickets;
  std::list<Player *>::iterator stricker;
  std::list<Player *>::iterator nonStricker;
  Boundary *boundary = new Boundary();

 public:
  BattingTeamRole(int numberOfPlayers)
      : TeamRole(numberOfPlayers), score(0), bowlsBowled(0), wickets(0) {}

  void setStricker(std::list<Player *>::iterator newStricker);
  std::list<Player *>::iterator getStricker();

  void setNonStricker(std::list<Player *>::iterator newNonStricker);
  std::list<Player *>::iterator getNonStricker();

  int getWickets();
  void incrementWickets();

  void changeEnds(bool isOverCompleted);

  void incrementScore(RunAction *run);
  int getScore();

  void incrementBallsBowled();

  void displayScoreBoard();
};

#endif