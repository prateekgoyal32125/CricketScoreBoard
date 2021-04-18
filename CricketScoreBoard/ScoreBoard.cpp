#include "ScoreBoard.h"

Team* ScoreBoard::getBattingTeam() {
  if (teamA->getCurrentRoleEnum() == TeamRoleEnum::BATTING) {
    return teamA;
  }

  if (teamB->getCurrentRoleEnum() == TeamRoleEnum::BATTING) {
    return teamB;
  }

  throw new exception("no batting team");
}

Team* ScoreBoard::getBowlingTeam() {
  if (teamA->getCurrentRoleEnum() == TeamRoleEnum::BOWLING) {
    return teamA;
  }

  if (teamB->getCurrentRoleEnum() == TeamRoleEnum::BOWLING) {
    return teamB;
  }

  throw new exception("no bowling team");
}

void ScoreBoard::displayScoreBoard() { getBattingTeam()->displayScoreBoard(); }

void ScoreBoard::switchInning() {
  Team* currentBattingTeam = getBattingTeam();
  Team* currentBowlingTeam = getBowlingTeam();

  currentBattingTeam->setRole(TeamRoleEnum::BOWLING);
  currentBowlingTeam->setRole(TeamRoleEnum::BATTING);
}

void ScoreBoard::displayResult() {
  BattingTeamRole* currentBattingTeamRole =
      (BattingTeamRole*)getBattingTeam()->getRole(TeamRoleEnum::BATTING);
  BattingTeamRole* currentBowlingTeamRole =
      (BattingTeamRole*)getBowlingTeam()->getRole(TeamRoleEnum::BATTING);

  if (currentBattingTeamRole->getScore() < currentBowlingTeamRole->getScore()) {
    printf("Result: %s won the match by %d runs", getBowlingTeam()->id.c_str(),
           (currentBowlingTeamRole->getScore() -
            currentBattingTeamRole->getScore()));
  } else if (currentBattingTeamRole->getScore() >
             currentBowlingTeamRole->getScore()) {
    printf("Result: %s won the match by %d wickets",
           getBattingTeam()->id.c_str(),
           ScoreBoardHelper::getWicketsRemaining(currentBattingTeamRole));
  } else {
    printf("Match tied!!");
  }
}

int ScoreBoard::getNumberOfPlayers() { return numberOfPlayers; };
