#include "TeamRole.h"

void TeamRole::setPlayerList(std::list<Player *> &newPlayerList) {
  playerList.assign(newPlayerList.begin(), newPlayerList.end());
}
