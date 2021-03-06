#include "BatsManRole.h"

void BatsmanRole::setStatus(BatsManStatus newStatus) { status = newStatus; }
BatsManStatus BatsmanRole::getStatus() { return status; }

void BatsmanRole::incrementScore(RunAction *run) {
  score += run->value;

  if (run->runType == RunType::FOUR) {
    boundary.four++;
  }

  if (run->runType == RunType::SIX) {
    boundary.six++;
  }
}

int BatsmanRole::getBallsFaced() { return ballsFaced; }

void BatsmanRole::incrementBallsFaced() { ++ballsFaced; }

std::tuple<std::string, int, int, int, int> BatsmanRole::displayScoreBoard(
    std::string name) {
  std::tuple<std::string, int, int, int, int> details{
      name + (status == BatsManStatus::BATTING ? "*" : ""), score,
      boundary.four, boundary.six, ballsFaced};
  return details;
}
