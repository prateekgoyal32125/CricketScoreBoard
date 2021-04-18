#ifndef TEAM_H
#define TEAM_H

#pragma once

#include <list>
#include <map>
#include <tuple>
#include <vector>

#include "BattingTeamRole.h"
#include "FieldingTeamRole.h"
#include "Generic.h"
#include "Player.h"
#include "TeamProfile.h"
#include "TeamRole.h"
#include "Variadic.h"

using namespace std;

class Team {
  std::list<Player *> playerList;
  std::map<PlayerId, std::list<Player *>::iterator> idToPlayerMap;

  std::list<TeamRole *> roles;
  std::map<TeamRoleEnum, std::list<TeamRole *>::iterator> roleEnumToRobleObjMap;

  TeamProfile *profile;
  TeamRoleEnum currentRoleEnum;

  int numberOfPlayers; 

 public:
  TeamId id;
  Team(string name, bool status, int numberOfPlayers)
      : id(name), numberOfPlayers(numberOfPlayers) {
    profile = TeamProfile::getTeam(name);
    initRoles();
    setRole(status ? TeamRoleEnum::BATTING : TeamRoleEnum::BOWLING);
  }

  void initRoles();

  void setRole(TeamRoleEnum newRole);

  TeamRoleEnum getCurrentRoleEnum();

  TeamRole *getCurrentRole();

  TeamRole *getRole(TeamRoleEnum roleEnum);

  void addPlayers(const std::list<Player *> &players);

  void displayScoreBoard();

  std::list<Player *>* getPlayerList();
};

#endif