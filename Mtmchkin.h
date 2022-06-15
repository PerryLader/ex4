#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include "utilities.h"
#include "./Cards/Card.h"
#include "./Players/Rogue.h"
#include "./Players/Wizard.h"
#include "./Players/Fighter.h"
#include <memory>
#include <map>
const std::string ROGUE = "Rogue";
const std::string WIZARD = "Wizard";
const std::string FIGHTER = "Fighter";
const std::string UNDEFINED = "Undefined";
const int MAX_PLAYER = 6;
const int MIN_DECK_CARDS=5;
const int START_ROW = 1;


class Mtmchkin {


std::queue<std::unique_ptr<Card>> m_cards;
std::vector<std::unique_ptr<Player>> m_players;
std::vector<std::unique_ptr<Player>> m_leadboard;
std::vector<bool> m_activePlayers;
int m_teamSize;
int m_roundCount = 1;

//helper methods
void initDeckMap(std::map<std::string, std::unique_ptr<Card>>& deck);
void getInputTeamSize();
void getInputPlayers();
void updateLeaderBoard();
bool checkClassIsLegal(const std::string& job);
bool checkIfNameIsLegal(const std::string& name);
void initActivePlayers();
void insertCard(const std::string cardName, int curr_row);
void validateEnoughCards();
void initLeaderBoard( std::vector<std::unique_ptr<Player>>& leaderBoard);

public:
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
