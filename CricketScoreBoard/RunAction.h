#ifndef RUNACTION_H
#define RUNACTION_H
#pragma once

#include "Action.h"
#include "Generic.h"
class RunAction : public Action {
 public:
  int value;
  RunType runType = RunType::NON_BOUNDARY;
  RunAction(int value) : value(value) {
    if (value == 4) {
      runType = RunType::FOUR;
    }

    if (value == 6) {
      runType = RunType::SIX;
    }
  }

  RunAction(int value, RunType runType) : value(value), runType(runType) {}
  bool isExtras();
};

#endif
