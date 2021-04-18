#ifndef GENERIC_H
#define GENERIC_H

#pragma once
#include <iostream>
#include <string>
#include <vector>

typedef std::string PlayerId;
typedef std::string TeamId;

struct Boundary {
 public:
  int four, six;
  Boundary() : four(0), six(0) {}
};

enum class ActionResults { FAIR_DELIVERY, UN_FAIR_DELIVERY };
enum class RunType { NON_BOUNDARY, FOUR, SIX, WIDE, BYE, LEG_BYE };
enum class EventTypes {
  RUN,
  OVER_END,
  FIRST_INNING_BREAK,
  WICKET,
  GAME_START,
  INNING_START,
  OVER_START,
  GAME_END,
};

struct Skill {};
enum class PlayerRoleEnum { BATTING, BOWLING, NONE };
enum class DismissalMode { NOT_OUT, RUN_OUT, BOWLED };
enum class BatsManStatus { OUT, BATTING, YET_TO_BAT };

#endif