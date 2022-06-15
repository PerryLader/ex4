#include "Mtmchkin.h"
#include <iostream>
#include <fstream>

#include "./Cards/Goblin.h"
#include "./Cards/Barfight.h"
#include "./Cards/Dragon.h"
#include "./Cards/Fairy.h"
#include "./Cards/Merchant.h"
#include "./Cards/Pitfall.h"
#include "./Cards/Treasure.h"
#include "./Cards/Vampire.h"
#include "./Exception.h"

using std::cin;
using std::ifstream;
using std::string;
void Mtmchkin::validateEnoughCards()
{
    if (m_cards.size() < MIN_DECK_CARDS)
    {
        throw DeckFileInvalidSize();
    }
}
void Mtmchkin::initDeckMap(std::map<string, std::unique_ptr<Card>> &deck)
{
    deck[GOBLIN] = std::unique_ptr<Card>(new Goblin());
    deck[FAIRY] = std::unique_ptr<Card>(new Fairy());
    deck[DRAGON] = std::unique_ptr<Card>(new Dragon());
    deck[VAMPIRE] = std::unique_ptr<Card>(new Vampire());
    deck[TREASURE] = std::unique_ptr<Card>(new Treasure());
    deck[PITFALL] = std::unique_ptr<Card>(new Pitfall());
    deck[MERCHANT] = std::unique_ptr<Card>(new Merchant());
    deck[BARFIGHT] = std::unique_ptr<Card>(new Barfight());
}
void Mtmchkin::insertCard(const string cardName, const int curr_row)
{
    std::map<string, std::unique_ptr<Card>> deck;
    initDeckMap(deck);
    if (deck.find(cardName) == deck.end())
    {
        throw DeckFileFormatError(curr_row);
    }
    else
    {
        m_cards.push(std::move(deck[cardName]));
    }
}
Mtmchkin::Mtmchkin(const std::string fileName)
{
    printStartGameMessage();
    ifstream file;
    int curr_row = START_ROW;
    file.open(fileName);
    if (file.fail())
    {
        throw DeckFileNotFound();
    }

    string cardName;
    while (!file.eof())
    {
        std::getline(file, cardName);
        try
        {
            insertCard(cardName, curr_row);
        }
        catch (const DeckFileFormatError &e)
        {
            std::cerr << e.what();
        }
        curr_row++;
    }

    validateEnoughCards();
    initActivePlayers();
    getInputTeamSize();
    initLeaderBoard(m_leadboard);
    getInputPlayers();
}
void Mtmchkin::initLeaderBoard(std::vector<std::unique_ptr<Player>> &leaderBoard)
{
    for (int i = 0; i < m_teamSize; i++)
    {
        leaderBoard.push_back(nullptr);
    }
}
void Mtmchkin::printLeaderBoard() const
{
    //void printPlayerLeaderBoard(int ranking, const Player &player);
    int rank = 0;
    printLeaderBoardStartMessage();
    while(m_leadboard[rank] != nullptr){
        printPlayerLeaderBoard(rank +1 , *m_leadboard[rank]);
        rank++;
    }
    for(int i = 0; i<m_teamSize ; i ++){
        if(m_activePlayers[i]){
            printPlayerLeaderBoard(rank +1 , *m_players[i]);
            rank++;
        }
    }
    for(; rank <m_teamSize ; rank++){
       printPlayerLeaderBoard(rank +1 , *m_leadboard[rank]);
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCount;
}

void Mtmchkin::initActivePlayers()
{
    for (int i = 0; i < MAX_PLAYER; i++)
    {
        m_activePlayers.push_back(false);
    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundCount);
    for (int i = 0; i < m_teamSize; i++)
    {
        if (m_activePlayers[i])
        {
            printTurnStartMessage(m_players[i]->getName());
            m_cards.front()->applyEncounter(*(m_players[i]));
            std::unique_ptr<Card> temp = std::move(m_cards.front());
            m_cards.push(std::move(temp));
            m_cards.pop();
        }
    }
    m_roundCount++;
    updateLeaderBoard();
}
bool Mtmchkin::isGameOver() const
{
    for (int i = 0; i < MAX_PLAYER; i++)
    {
        if (m_activePlayers[i])
        {
            return false;
        }
    }
    return true;
}
void Mtmchkin::updateLeaderBoard()
{
    for (int i = 0; i < m_teamSize; i++)
    {
        if (m_activePlayers[i])
        {
            if (m_players[i]->isKnockedOut())
            {
                for (int j = m_teamSize - 1; j >= 0; j--)
                {
                    if (m_leadboard[j] == nullptr)
                    {
                        m_leadboard[j] = std::move(m_players[i]);
                        m_activePlayers[i] = false;
                    }
                }
            }
            else if (m_players[i]->isWinner())
            {
                for (int j = 0; j < m_teamSize; j++)
                {
                    if (m_leadboard[j] == nullptr)
                    {
                        m_leadboard[j] = std::move(m_players[i]);
                        m_activePlayers[i] = false;
                    }
                }
            }
        }
    }
}
// dosent know how to handle cases that start with an int and end with char like "3a"
void Mtmchkin::getInputTeamSize()
{

    printEnterTeamSizeMessage();
    string choosen;
    std::getline(cin, choosen);
    while (choosen.length() != 1 || choosen[0] < 50 || choosen[0] > 54 || !cin.eof())
    {
        printInvalidTeamSize();
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(cin, choosen);
    }
    try
    {
        m_teamSize = stoi(choosen);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Mtmchkin::checkIfNameIsLegal(const string &name)
{
    if (name.length() > 15)
    {
        printInvalidName();
        return false;
    }
    int currChar;
    for (char i : name)
    {
        currChar = int(i);
        if ((currChar > 122) || (currChar < 97 && currChar > 90) || (currChar < 65))
        {
            printInvalidName();
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkClassIsLegal(const string &job)
{
    if (!(job == ROGUE || job == WIZARD || job == FIGHTER))
    {
        printInvalidClass();
        return false;
    }
    return true;
}
// fix all get line problems

void Mtmchkin::getInputPlayers()
{
    for (int i = 0; i < m_teamSize; i++)
    {
        string input;
        std::getline(cin, input);

        int pos = input.find(" ");
        string name = input.substr(0, pos);
        string job;
        if ((unsigned int) pos < input.length())
        {
            job = input.substr(pos + 1, input.length());
        }
        else
        {
            job = UNDEFINED;
        }
        bool illegal = !checkIfNameIsLegal(name) || !checkClassIsLegal(job);
        while (illegal)
        {
            std::getline(cin, input);
            pos = input.find(" ");
            name = input.substr(0, pos);
            if ((unsigned int)pos < input.length())
            {
                job = input.substr(pos + 1, input.length());
            }
            else
            {
                job = UNDEFINED;
            }
            illegal = !checkIfNameIsLegal(name) || !checkClassIsLegal(job);
        }
        if (job == ROGUE)
        {
            m_players[i] = (std::unique_ptr<Player>(new Rogue(name)));
        }
        if (job == WIZARD)
        {
            m_players[i] = (std::unique_ptr<Player>(new Wizard(name)));
        }
        if (job == FIGHTER)
        {
            m_players[i] = (std::unique_ptr<Player>(new Fighter(name)));
        }
        m_activePlayers[i] = true;
    }
}
