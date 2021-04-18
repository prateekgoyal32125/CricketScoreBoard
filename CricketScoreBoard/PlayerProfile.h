#ifndef PLAYERPROFILE_H
#define PLAYERPROFILE_H

#pragma once

#include <string>

class PlayerProfile {
 public:
  std::string name;
  /*std::vector<Skill> skills;
  time_t birthDate;
  std::string birthPlace;*/

  PlayerProfile(std::string name) : name(name) {}

  static PlayerProfile *getPlayer(std::string name);
};

#endif