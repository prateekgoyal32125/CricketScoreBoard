#include "Team.h"

void Team::initRoles() {
  roles.push_front(new BattingTeamRole(numberOfPlayers));
  roleEnumToRobleObjMap[TeamRoleEnum::BATTING] = roles.begin();

  roles.push_front(new FieldingTeamRole(numberOfPlayers));
  roleEnumToRobleObjMap[TeamRoleEnum::BOWLING] = roles.begin();
}

TeamRole *Team::getCurrentRole() { return getRole(currentRoleEnum); }
void Team::setRole(TeamRoleEnum newRole) { currentRoleEnum = newRole; }

TeamRoleEnum Team::getCurrentRoleEnum() { return currentRoleEnum; }

TeamRole *Team::getRole(TeamRoleEnum roleEnum) {
  return *roleEnumToRobleObjMap[roleEnum];
}


void Team::addPlayers(const std::list<Player *> &players) {
  playerList.assign(players.begin(), players.end());
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

std::list<Player*>* Team::getPlayerList() { return &playerList; }
