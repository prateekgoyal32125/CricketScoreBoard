#ifndef EVENTS_h
#define EVENTS_h
#pragma once

#include "Generic.h"
#include "RunAction.h"

class ScoreBoard;
class RunEvent;

class Event {
 public:
  virtual ActionResults takeAction(ScoreBoard* scoreBoard) = 0;
  virtual void getEventType() = 0;
  static Event* getEvent(std::string action);
};

class GameStartEvent : public Event {
 public:
  ActionResults takeAction(ScoreBoard* scoreBoard) {}
};

class OverStartEvent : public Event {
 public:
  ActionResults takeAction(ScoreBoard* scoreBoard) {}
};

class RunEvent : public Event {
 protected:
  RunAction* run;

 public:
  RunEvent(RunAction* run) : run(run) {}
  ActionResults takeAction(ScoreBoard* scoreBoard);
  void getEventType();
};

class OverEndEvent : public Event {
 public:
  OverEndEvent() {}
  ActionResults takeAction(ScoreBoard* scoreBoard);
  void getEventType();
};

class InningEndEvent : public Event {
 public:
  InningEndEvent() {}
  ActionResults takeAction(ScoreBoard* scoreBoard);
  void getEventType();
};

class WicketEvent : public Event {
 public:
  ActionResults takeAction(ScoreBoard* scoreBoard);
  void getEventType();
};

#endif