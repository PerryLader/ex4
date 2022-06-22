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
#include "./Cards/Gang.h"

using std::cin;
using std::ifstream;
using std::string;
void Mtmchkin::validateEnoughCards() const
{
    if (m_cards.size() < (unsigned int)MIN_DECK_CARDS)
    {
        throw DeckFileInvalidSize();
    }
}
void Mtmchkin::initDeckMap(std::map<string, std::unique_ptr<Card>> &deck) const
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

void Mtmchkin::initBattleDeckMap(std::map<std::string, std::unique_ptr<BattleCard>> &deck) const
{
    deck[GOBLIN] = std::unique_ptr<BattleCard>(new Goblin());
    deck[DRAGON] = std::unique_ptr<BattleCard>(new Dragon());
    deck[VAMPIRE] = std::unique_ptr<BattleCard>(new Vampire());
}

void Mtmchkin::initPlayersMap(std::map<std::string, std::unique_ptr<Player>> &map, std::string name) const
{
    map[ROGUE] = std::unique_ptr<Player>(new Rogue(name));
    map[WIZARD] = std::unique_ptr<Player>(new Wizard(name));
    map[FIGHTER] = std::unique_ptr<Player>(new Fighter(name));
}

void Mtmchkin::insertCard(const string cardName, int curr_row)
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

void Mtmchkin::insertGang(const std::vector<std::string> gang, int &curr_row)
{
    std::map<string, std::unique_ptr<BattleCard>> deck;
    initBattleDeckMap(deck);
    Gang *gangCards = new Gang(gang);
    std::unique_ptr<Card> ptr(gangCards);
    m_cards.push(std::move(ptr));
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_players()
{
    std::map<string, std::unique_ptr<BattleCard>> deck;
    initBattleDeckMap(deck);
    printStartGameMessage();
    ifstream file;
    int curr_row = START_ROW;
    file.open(fileName);
    if (file.fail())
    {
        throw DeckFileNotFound();
    }
    string cardName = "";
    while (!file.eof())
    {
        std::getline(file, cardName);
        if (cardName != "")
        {
            if (cardName == GANG)
            {
                std::vector<std::string> gang;
                while (cardName != ENDGANG && !file.eof())
                {
                    std::getline(file, cardName);
                    if (cardName != ENDGANG)
                    {
                        curr_row++;
                        if (deck.find(cardName) == deck.end())
                        {
                            throw DeckFileFormatError(curr_row);
                        }
                        gang.push_back(cardName);
                    }
                }
                if (file.eof())
                {
                    throw DeckFileFormatError(curr_row);
                }
                else
                {
                    insertGang(gang, curr_row);
                }
            }
            else
            {
                insertCard(cardName, curr_row);
                curr_row++;
            }
        }
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
    int rank = 0;
    printLeaderBoardStartMessage();
    for (int i = 0; (unsigned int)i < m_leadboard.size(); i++)
    {
        if (m_leadboard[rank] != nullptr)
        {
            printPlayerLeaderBoard(rank + 1, *m_leadboard[rank]);
            rank++;
        }
    }
    for (int i = 0; i < m_teamSize; i++)
    {
        if (m_activePlayers[i])
        {
            printPlayerLeaderBoard(rank + 1, *m_players[i]);
            rank++;
        }
    }
    for (; rank < m_teamSize; rank++)
    {
        printPlayerLeaderBoard(rank + 1, *m_leadboard[rank]);
    }
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_roundCount - 1;
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
    if (isGameOver())
    {
        printGameEndMessage();
    }
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
void Mtmchkin::getInputTeamSize()
{

    printEnterTeamSizeMessage();
    string choosen;
    std::getline(cin, choosen);
    while (choosen.length() != 1 || choosen[0] < 50 || choosen[0] > 54)
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
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

bool Mtmchkin::checkIfNameIsLegal(const string &name) const
{
    if (name.length() > 15)
    {
        return false;
    }
    int currChar;
    for (char i : name)
    {
        currChar = int(i);
        if ((currChar > 122) || (currChar < 97 && currChar > 90) || (currChar < 65))
        {
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkPlayersInput(std::string input, std::map<std::string, std::unique_ptr<Player>> &map,
                                 std::string &job, std::string &name) const
{
    int pos = input.find(" ");
    if ((unsigned int)pos == std::string::npos || (unsigned int)pos + 1 == input.length())
    {
        printInvalidName();
        return true;
    }
    else
    {
        name = input.substr(0, pos);
        if ((unsigned int)pos < input.length())
        {
            job = input.substr(pos + 1, input.length());
        }
        else
        {
            job = UNDEFINED;
        }
        if (checkIfNameIsLegal(name))
        {
            initPlayersMap(map, name);
            if (map.find(job) == map.end())
            {
                printInvalidClass();
                return true;
            }
        }
        else
        {
            printInvalidName();
            return true;
        }
    }
    return false;
}

void Mtmchkin::getInputPlayers()
{
    for (int i = 0; i < m_teamSize; i++)
    {
        std::map<std::string, std::unique_ptr<Player>> map;
        string input;
        printInsertPlayerMessage();
        std::getline(cin, input);
        string name;
        string job;
        bool illegal = checkPlayersInput(input, map, job, name);
        while (illegal)
        {
            std::getline(cin, input);
            illegal = checkPlayersInput(input, map, job, name);
        }
        m_players.push_back(std::move(map[job]));
        m_activePlayers[i] = true;
    }
}
