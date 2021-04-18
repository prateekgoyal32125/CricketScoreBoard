#include "ScoreBoardHelper.h"

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