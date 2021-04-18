#include "Events.h"

#include <string>

#include "Generic.h"
#include "ScoreBoard.h"
#include "Team.h"

ActionResults RunEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)))
      ->incrementScore(run);

  if (run->isExtras()) return ActionResults::UN_FAIR_DELIVERY;
  return ActionResults::FAIR_DELIVERY;
};

void RunEvent::getEventType() { cout << "its a run event"; }

ActionResults OverEndEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)))
      ->changeEnds(true);

  return ActionResults::FAIR_DELIVERY;
};
void OverEndEvent::getEventType() { cout << "its a over end event event\n"; }

ActionResults WicketEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  return ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)))
      ->handleOut();
};

void WicketEvent::getEventType() { cout << "its a Wicket event\n"; }

ActionResults InningEndEvent::takeAction(ScoreBoard* scoreBoard) {
  scoreBoard->switchInning();
  return ActionResults::FAIR_DELIVERY;
};

void InningEndEvent::getEventType() { cout << "its a interval event\n"; }

Event* Event::getEvent(std::string action) {
  if (action == "OVER_End") {
    return new OverEndEvent();
  }

  if (action == "INNINg_END") {
    return new InningEndEvent();
  }

  if (action == "Wd") {
    return new RunEvent(new RunAction(1, RunType::WIDE));
  }

  if (action == "W") {
    return new WicketEvent();
  }

  return new RunEvent(new RunAction(std::stoi(action)));
};