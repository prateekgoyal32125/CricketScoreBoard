#include "BattingTeamRole.h"

void BattingTeamRole::setStricker(std::list<Player *>::iterator newStricker) {
  stricker = newStricker;
}
std::list<Player *>::iterator BattingTeamRole::getStricker() {
  return stricker;
}

std::list<Player *>::iterator BattingTeamRole::getNonStricker() {
  return nonStricker;
}
void BattingTeamRole::setNonStricker(
    std::list<Player *>::iterator newNonStricker) {
  nonStricker = newNonStricker;
}

void BattingTeamRole::changeEnds(bool isOverCompleted) {
  std::list<Player *>::iterator tmp = stricker;
  stricker = nonStricker;
  nonStricker = tmp;
}

void BattingTeamRole::incrementScore(RunAction *run) {
  score += run->value;
}
int BattingTeamRole::getScore() { return score; }

int BattingTeamRole::getWickets() { return wickets; }
void BattingTeamRole::incrementWickets() { ++wickets; }

void BattingTeamRole::incrementBallsBowled() { ++bowlsBowled; }


void BattingTeamRole::displayScoreBoard() {
  std::string total = std::to_string(score) + "/" + std::to_string(wickets);
  printf("Total: %s\n", total.c_str());
  std::string overs =
      std::to_string(bowlsBowled / 6) + "." + std::to_string(bowlsBowled % 6);
  printf("Overs: %s\n", overs.c_str());
}