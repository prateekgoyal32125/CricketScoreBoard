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
  Team* currentBattingTeam = getBattingTeam();
  Team* currentBowlingTeam = getBowlingTeam();
  cout << currentBattingTeam->getScore() << endl;
  if (currentBattingTeam->getScore() < currentBowlingTeam->getScore()) {
    printf("Result: %s won the match by %d runs",
           currentBowlingTeam->id.c_str(),
           (currentBowlingTeam->getScore() - currentBattingTeam->getScore()));
  } else if (currentBattingTeam->getScore() > currentBowlingTeam->getScore()) {
    printf("Result: %s won the match by %d wickets",
           currentBattingTeam->id.c_str(),
           currentBattingTeam->getRemainingWickets());
  } else {
  }
}
