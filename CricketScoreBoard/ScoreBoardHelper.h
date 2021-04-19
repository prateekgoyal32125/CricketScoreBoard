#ifndef SCOREBOARDHELPER_H
#define SCOREBOARDHELPER_H

#pragma once
#include <list>

#include "ScoreBoard.h"
#include "Team.h"

class ScoreBoardHelper {
 public:
  static bool isAllOut(Team* battingTeam);
  static bool isInningOver(ScoreBoard* scoreBoard);
  static BatsmanRole* getBatsManRole(std::list<Player*>::iterator playerRef);
  static BattingTeamRole* getBattingTeamRole(Team* battingTeam);
  static int getWicketsRemaining(BattingTeamRole* battingTeam);
};

#endif