#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#pragma once
#include <iostream>

#include "Generic.h"
#include "Player.h"
#include "Team.h"
using namespace std;

class ScoreBoard {
  Team* teamA;
  Team* teamB;
  int numberOfovers;
  string name;

 public:
  ScoreBoard(string name, string teamAName, string teamBName, int numberOfOvers)
      : name(name),
        numberOfovers(numberOfOvers),
        teamA(new Team(teamAName, true)),
        teamB(new Team(teamBName, false)) {}

  Team* getBattingTeam();
  Team* getBowlingTeam();

  void displayScoreBoard();

  void switchInning();

  void displayResult();
};

#endif