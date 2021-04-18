#include "Events.h"

#include <string>

#include "Generic.h"
#include "ScoreBoard.h"
#include "ScoreBoardHelper.h"
#include "Team.h"

ActionResults InningStartEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  BattingTeamRole* teamRole =
      ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)));

  auto playerList = battingTeam->getPlayerList();

  teamRole->setStricker(playerList->begin());
  teamRole->setNonStricker(++(playerList->begin()));

  BatsmanRole* stricker =
      ScoreBoardHelper::getBatsManRole(teamRole->getStricker());

  stricker->setStatus(BatsManStatus::BATTING);
  BatsmanRole* nonStricker =
      ScoreBoardHelper::getBatsManRole(teamRole->getNonStricker());

  nonStricker->setStatus(BatsManStatus::BATTING);
  return ActionResults::UN_FAIR_DELIVERY;
};

void InningStartEvent::getEventType() { cout << "its inning start event "; }

ActionResults RunEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  BattingTeamRole* teamRole = ScoreBoardHelper::getBattingTeamRole(battingTeam);
  BatsmanRole* playerRole =
      ScoreBoardHelper::getBatsManRole(teamRole->getStricker());

  teamRole->incrementScore(run);

  if (run->isExtras()) return ActionResults::UN_FAIR_DELIVERY;

  playerRole->incrementScore(run);
  playerRole->incrementBallsFaced();
  if ((run->value) & 1) teamRole->changeEnds(false);

  return ActionResults::FAIR_DELIVERY;
};

void RunEvent::getEventType() { cout << "its a run event"; }

ActionResults OverEndEvent::takeAction(ScoreBoard* scoreBoard) {
  BattingTeamRole* teamRole =
      ScoreBoardHelper::getBattingTeamRole(scoreBoard->getBattingTeam());
  teamRole->changeEnds(true);
  return ActionResults::FAIR_DELIVERY;
};
void OverEndEvent::getEventType() { cout << "its a over end event event\n"; }

ActionResults WicketEvent::takeAction(ScoreBoard* scoreBoard) {
  Team* battingTeam = scoreBoard->getBattingTeam();
  BattingTeamRole* teamRole =
      ((BattingTeamRole*)(battingTeam->getRole(TeamRoleEnum::BATTING)));

  auto playerRef = teamRole->getStricker();
  BatsmanRole* playerRole = ScoreBoardHelper::getBatsManRole(playerRef);

  teamRole->incrementWickets();
  playerRole->setStatus(BatsManStatus::OUT);
  playerRole->incrementBallsFaced();

  if (ScoreBoardHelper::isAllOut(battingTeam)) {
    return ActionResults::FAIR_DELIVERY;
  }
  
  auto playerList = battingTeam->getPlayerList();

  while (playerRef != playerList->end() &&
         (playerRole->getStatus() != BatsManStatus::YET_TO_BAT)) {
    playerRef++;
    playerRole = ScoreBoardHelper::getBatsManRole(playerRef);
  }

  if (playerRef == playerList->end()) {
    throw new std::exception(" SomeThing Went Wrong");
  }

  teamRole->setStricker(playerRef);
  playerRole->setStatus(BatsManStatus::BATTING);

  return ActionResults::FAIR_DELIVERY;
};

void WicketEvent::getEventType() { cout << "its a Wicket event\n"; }

ActionResults InningEndEvent::takeAction(ScoreBoard* scoreBoard) {
  scoreBoard->switchInning();
  return ActionResults::FAIR_DELIVERY;
};

void InningEndEvent::getEventType() { cout << "its a interval event\n"; }

Event* Event::getEvent(std::string action) {
  if (action == "INNING_START_ev") {
    return new InningStartEvent();
  }

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