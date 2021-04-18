#include "TeamProfile.h"

TeamProfile *TeamProfile::getTeam(std::string name) {
  return new TeamProfile(name);
}