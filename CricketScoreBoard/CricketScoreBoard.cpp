// CricketScoreBoard.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//

#include <iostream>

#include "Events.h"
#include "Generic.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "Team.h"
#include "Variadic.h"
#include "ScoreBoardHelper.h"

using namespace std;

ScoreBoard *scoreBoard;
int numberOfPlayers, numberOfOvers;

void getBattingOrder() {
  Team *battingTeam = scoreBoard->getBattingTeam();

  cout << "Batting Order for " << battingTeam->id << "\n\n";
  std::list<Player *> players;
  for (int i = 0; i < numberOfPlayers; i++) {
    string playerName;
    cin >> playerName;
    players.push_back(new Player(playerName, battingTeam->id));
  }

  battingTeam->addPlayers(players);

  cout << "Created the  " << battingTeam->id << "\n\n";
}

void startInning(std::string inningId) {
  getBattingOrder();

  Team *battingTeam = scoreBoard->getBattingTeam();

  printf("---Starting the %s inning for team %s----\n\n\n ", inningId.c_str(),
         battingTeam->id.c_str());

  Event *ev = Event::getEvent("INNING_START_ev");
  ActionResults result = ev->takeAction(scoreBoard);

  for (int i = 0; i < numberOfOvers; i++) {
    int ballsBowled = 0;
    while (!ScoreBoardHelper::isAllOut(battingTeam) && ballsBowled < 6) {
      string action;
      cin >> action;
      Event *ev = Event::getEvent(action);
      ActionResults result = ev->takeAction(scoreBoard);
      
      if (result == ActionResults::FAIR_DELIVERY) {
        ballsBowled++;
      }
    }

    Event *ev = Event::getEvent("OVER_End");
    ev->takeAction(scoreBoard);

    scoreBoard->displayScoreBoard();

    if (ScoreBoardHelper::isAllOut(battingTeam)) {
      break;
    }
  }
  printf("---Inning ended----\n\n\n ");
}

void displayFinalResults() {
  cout << "Game Ended!\n\n\n";
  scoreBoard->displayResult();
}

int main() {
  cout << "No. of players for each team:\n";
  cin >> numberOfPlayers;

  cout << "No.of overs :\n";
  cin >> numberOfOvers;

  scoreBoard = new ScoreBoard("Classic ScoreBoard", "teamA", "teamB",
                              numberOfOvers, numberOfPlayers);

  startInning("1st Inning");
  Event *ev = Event::getEvent("INNINg_END");
  ev->takeAction(scoreBoard);

  startInning("2nd Inning");

  displayFinalResults();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add
//   Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project
//   and select the .sln file
