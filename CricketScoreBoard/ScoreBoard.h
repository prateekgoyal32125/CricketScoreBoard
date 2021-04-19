#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#pragma once
#include <iostream>

#include "Generic.h"
#include "Player.h"
#include "Team.h"
#include "ScoreBoardHelper.h"

using namespace std;

class ScoreBoard {
  Team* teamA;
  Team* teamB;
  int numberOfovers, numberOfPlayers;
  bool isFirstHalfComplete;
  string name;

 public:
  ScoreBoard(string name, string teamAName, string teamBName, int numberOfOvers,
             int numberOfPlayers)
      : name(name),
        numberOfovers(numberOfOvers),
        numberOfPlayers(numberOfPlayers),
        teamA(new Team(teamAName, true, numberOfPlayers)),
        teamB(new Team(teamBName, false, numberOfPlayers)),
        isFirstHalfComplete(false) {}

  Team* getBattingTeam();
  Team* getBowlingTeam();

  void setIsFirstHalfComplete();
  bool getIsFirstHalfComplete();

  int getNumberOfPlayers();
  void displayScoreBoard();


  void switchInning();

  void displayResult();
};

#endif