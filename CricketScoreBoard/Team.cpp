#include "Team.h"

void Team::initRoles() {
  roles.push_front(new BattingTeamRole(playerList));
  roleEnumToRobleObjMap[TeamRoleEnum::BATTING] = roles.begin();

  roles.push_front(new FieldingTeamRole(playerList));
  roleEnumToRobleObjMap[TeamRoleEnum::BOWLING] = roles.begin();
}

void Team::setRole(TeamRoleEnum newRole) { currentRoleEnum = newRole; }
TeamRoleEnum Team::getCurrentRoleEnum() { return currentRoleEnum; }

TeamRole *Team::getCurrentRole() { return getRole(currentRoleEnum); }
TeamRole *Team::getRole(TeamRoleEnum roleEnum) {
  return *roleEnumToRobleObjMap[roleEnum];
}

bool Team::isAllout() {
  return (currentRoleEnum == TeamRoleEnum::BATTING) &&
         ((BattingTeamRole *)getCurrentRole())->isAllOut();
}

void Team::addPlayers(const std::list<Player *> &players) {
  playerList.assign(players.begin(), players.end());

  for (auto pr : roleEnumToRobleObjMap) {
    (*(pr.second))->setPlayerList(playerList);
  }
}

void Team::displayScoreBoard() {
  VariadicTable<std::string, int, int, int, int> vt(
      {"Player Name", "Score", "4s", "6s", "Balls"}, 12);
  vt.setColumnFormat(
      {VariadicTableColumnFormat::AUTO, VariadicTableColumnFormat::AUTO,
       VariadicTableColumnFormat::AUTO, VariadicTableColumnFormat::AUTO,
       VariadicTableColumnFormat::AUTO});
  vt.setColumnPrecision({1, 3, 3, 3, 3});

  for (Player *player : playerList) {
    tuple<string, int, int, int, int> details = player->displayScoreBoard();
    vt.addRow(get<0>(details), get<1>(details), get<2>(details),
              get<3>(details), get<4>(details));
  }

  vt.print(std::cout);

  getCurrentRole()->displayScoreBoard();
}

int Team::getScore() {
  return ((BattingTeamRole *)getRole(TeamRoleEnum::BOWLING))->getScore();
}

int Team::getRemainingWickets() {
  return ((int)playerList.size() -
          ((BattingTeamRole *)getRole(TeamRoleEnum::BOWLING))->getWickets());
}