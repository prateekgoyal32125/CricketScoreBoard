#include "ScoreBoardHelper.h"


bool ScoreBoardHelper::isInningOver(ScoreBoard* scoreBoard) {
  auto currentBattingTeam = scoreBoard->getBattingTeam();
  bool isAllOut = ScoreBoardHelper::isAllOut(currentBattingTeam);
  if (isAllOut) {
    return true;
  }

  if (!scoreBoard->getIsFirstHalfComplete()) {
    return false; 
  }

  auto previousBattingTeam = scoreBoard->getBowlingTeam();

  int firstInningScore =
      ((BattingTeamRole*)(previousBattingTeam->getRole(TeamRoleEnum::BATTING)))
          ->getScore();

  int secondInningScore =
      ((BattingTeamRole*)(currentBattingTeam->getRole(TeamRoleEnum::BATTING)))
          ->getScore();

  int scoreDiff = secondInningScore - firstInningScore;
  return (scoreDiff > 0 ) ;
}

bool ScoreBoardHelper::isAllOut(Team* battingTeam) {
  BattingTeamRole* teamRole =
      ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)));
  int totalFallenWickets = teamRole->getWickets();

  bool isAllOut = (totalFallenWickets + 1) == (teamRole->getNumberOfPlayers());

  return isAllOut;
}

BatsmanRole* ScoreBoardHelper::getBatsManRole(
    std::list<Player*>::iterator playerRef) {
  return (BatsmanRole*)((*playerRef)->getRole(PlayerRoleEnum::BATTING));
}

BattingTeamRole* ScoreBoardHelper::getBattingTeamRole(Team* battingTeam) {
  return ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)));
}

int ScoreBoardHelper::getWicketsRemaining(BattingTeamRole* battingTeam) {
  return (battingTeam->getNumberOfPlayers() - battingTeam->getWickets());
}
