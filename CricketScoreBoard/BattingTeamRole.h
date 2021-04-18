#ifndef BATTINGTEAMROLE_H
#define BATTINGTEAMROLE_H

#pragma once

#include <string>

#include "TeamRole.h"

class BattingTeamRole : public TeamRole {
 protected:
  int score;
  int oversCompleted;
  int wickets;
  std::list<Player *>::iterator stricker;
  std::list<Player *>::iterator nonStricker;
  Boundary *boundary = new Boundary();

 public:
  BattingTeamRole(std::list<Player *> &playerList)
      : TeamRole(playerList), score(0), oversCompleted(0), wickets(0) {}

  virtual void setPlayerList(std::list<Player *> &newPlayerList);
  void setStricker(std::list<Player *>::iterator newStricker);

  void setNonStricker(std::list<Player *>::iterator newNonStricker);

  BatsmanRole *getBatsManRole(std::list<Player *>::iterator playerRef);
  std::list<Player *>::iterator nextStricker();

  bool isAllOut();

  ActionResults handleOut();

  void changeEnds(bool isOverCompleted);

  void incrementScore(RunAction *run);

  int getScore();

  int getWickets();

  void displayScoreBoard();
};

#endif