#include "BattingTeamRole.h"

void BattingTeamRole::setPlayerList(std::list<Player *> &newPlayerList) {
  TeamRole::setPlayerList(newPlayerList);

  setStricker(playerList.begin());
  setNonStricker(++playerList.begin());
}

void BattingTeamRole::setStricker(std::list<Player *>::iterator newStricker) {
  stricker = newStricker;
  getBatsManRole(newStricker)->setStatus(BatsManStatus::BATTING);
}

void BattingTeamRole::setNonStricker(
    std::list<Player *>::iterator newNonStricker) {
  nonStricker = newNonStricker;
  getBatsManRole(nonStricker)->setStatus(BatsManStatus::BATTING);
}

BatsmanRole *BattingTeamRole::getBatsManRole(
    std::list<Player *>::iterator playerRef) {
  return (BatsmanRole *)(*playerRef)->getRole(PlayerRoleEnum::BATTING);
}

std::list<Player *>::iterator BattingTeamRole::nextStricker() {
  std::list<Player *>::iterator playerRef = stricker;
  playerRef++;

  while (
      playerRef != playerList.end() &&
      (getBatsManRole(playerRef)->getStatus() != BatsManStatus::YET_TO_BAT)) {
    playerRef++;
  }

  if (playerRef == playerList.end()) {
    throw new std::exception(" inings over ");
  }

  return playerRef;
}

bool BattingTeamRole::isAllOut() {
  return ((wickets + 1) == (int)playerList.size());
}

ActionResults BattingTeamRole::handleOut() {
  try {
    wickets++;
    getBatsManRole(stricker)->setStatus(BatsManStatus::OUT);

    if (isAllOut()) {
      return ActionResults::ALL_OUT;
    }

    std::list<Player *>::iterator newStricker = nextStricker();
    getBatsManRole(newStricker)->setStatus(BatsManStatus::BATTING);
    setStricker(newStricker);
  } catch (std::exception ex) {
    std::cout << "exception in handle out";
  }

  return ActionResults::FAIR_DELIVERY;
}

void BattingTeamRole::changeEnds(bool isOverCompleted) {
  std::list<Player *>::iterator tmp = stricker;
  stricker = nonStricker;
  nonStricker = tmp;

  if (isOverCompleted) oversCompleted++;
}

void BattingTeamRole::incrementScore(RunAction *run) {
  score += run->value;

  if (run->runType == RunType::NON_BOUNDARY || run->runType == RunType::FOUR ||
      run->runType == RunType::SIX) {
    getBatsManRole(stricker)->incrementScore(run);

    if (run->value & 1) {
      changeEnds(false);
    }

    return;
  }
}

int BattingTeamRole::getScore() { return score; }

int BattingTeamRole::getWickets() { return wickets; }

void BattingTeamRole::displayScoreBoard() {
  std::string total = std::to_string(score) + "/" + std::to_string(wickets);
  printf("Total: %s\n", total.c_str());
  std::string overs = std::to_string(oversCompleted);
  printf("Overs: %s\n", overs.c_str());
}