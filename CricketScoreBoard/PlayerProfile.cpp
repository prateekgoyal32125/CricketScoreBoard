#include "PlayerProfile.h"

PlayerProfile *PlayerProfile::getPlayer(std::string name) {
  return new PlayerProfile(name);
}
