
#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <list>
#include <map>
#include <tuple>

#include "BatsManRole.h"
#include "Events.h"
#include "Generic.h"
#include "PlayerProfile.h"
#include "PlayerRole.h"

class Player {
  TeamId teamId;
  PlayerProfile *playerProfile;
  PlayerRoleEnum currentRoleEnum;
  std::list<PlayerRole *> roles;
  std::map<PlayerRoleEnum, std::list<PlayerRole *>::iterator>
      roleEnumToRobleObjMap;

 public:
  PlayerId id;

  Player(const std::string &playerName, const TeamId &teamId)
      : id(playerName), teamId(teamId) {
    playerProfile = PlayerProfile::getPlayer(playerName);
    initRoles();
    setRole(PlayerRoleEnum::BATTING);
  }

  void initRoles();

  PlayerRole *getCurrentRole();

  PlayerRole *getRole(PlayerRoleEnum roleEnum);

  void setRole(PlayerRoleEnum newRoleEnum);

  std::tuple<std::string, int, int, int, int> displayScoreBoard();
};

#endif