#include "Player.h"

void Player::initRoles() {
  roles.push_front(new BatsmanRole());
  roleEnumToRobleObjMap[PlayerRoleEnum::BATTING] = roles.begin();
}

PlayerRole *Player::getCurrentRole() {
  return *roleEnumToRobleObjMap[currentRoleEnum];
}

PlayerRole *Player::getRole(PlayerRoleEnum roleEnum) {
  return *roleEnumToRobleObjMap[roleEnum];
}

void Player::setRole(PlayerRoleEnum newRoleEnum) {
  currentRoleEnum = newRoleEnum;
}

std::tuple<std::string, int, int, int, int> Player::displayScoreBoard() {
  return getCurrentRole()->displayScoreBoard(playerProfile->name);
}