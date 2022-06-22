#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include "utilities.h"
#include "./Cards/Card.h"
#include "./Players/Rogue.h"
#include "./Players/Wizard.h"
#include "./Players/Fighter.h"
#include "./Cards/BattleCard.h"
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

//------------------------helper methods--------------------------
//the function initilize map with pairs of string and unique_ptr ofcards type
void initDeckMap(std::map<std::string, std::unique_ptr<Card>>& deck) const;
//the function initilize map with pairs of string and unique_ptr of battle cards type
void initBattleDeckMap(std::map<std::string, std::unique_ptr<BattleCard>> &deck) const;
//the function asks the user for team size and puts it in m_teamSize
void getInputTeamSize();
//the function asks the user for name and types of all players and put it in m_players
void getInputPlayers();
//update m_leadboard vector according to leaderboard convention
void updateLeaderBoard();
//return true if name is leagal according to the name convention
bool checkIfNameIsLegal(const std::string& name) const;
//initilize m_activePlayers vactor to contains 6 false cells
void initActivePlayers();
//the function insert a card to m_cards according to cardName.
//if the card name was illigal,DeckFileFormatError exeption is thrown
void insertCard(const std::string cardName, int curr_row);
//throw a DeckFileInvalidSize exeption if there is less then 5 cards in m_cards
void validateEnoughCards() const;
//initilize m_leaderBoard vactor to contains 6 nullptr cells
void initLeaderBoard();
//the function insert a gang card to m_cards according to the vector gang.
//if one of the card names was illigal,DeckFileFormatError exeption is thrown
void insertGang(const std::vector<std::string> gang, int& curr_row);
//the fucntion return true if the input of the player name and his job is ligall according to convention
//if so, @para job gets the proper string and @para name gets the proper string 
bool checkPlayersInput(std::string input, std::map<std::string, std::unique_ptr<Player>>& map,
 std::string& name, std::string& job) const;
//the function initilize map with pairs of string and unique_ptr of players with name @param name
void initPlayersMap(std::map<std::string, std::unique_ptr<Player>>& map, std::string name) const;
void initOnStartup();

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
    * Prints the leaderBoard of the game at a given stage of the game - according to the 
    *instruction in the exercise document.
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
