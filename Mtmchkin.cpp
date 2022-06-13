#include "Mtmchkin.h"
#include <iostream>
using std::cin;
using std::string;
using std::unique_ptr;

void Mtmchkin::playRound()
{
    for (int i = 0; i < m_teamSize; i++)
    {
        if (m_activePlayers[i])
        {
            m_cards.front()->applyEncounter(*(m_players[i]));
            unique_ptr<Card> temp = std::move(m_cards.front());
            m_cards.push(temp);
            m_cards.pop();
        }
    }
    updateLeaderBoard();
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

    printStartGameMessage();
    printEnterTeamSizeMessage();
    string choosen;
    std::getline(cin, choosen);
    while (choosen.length() != 1 || choosen[0] < 50 || choosen[0] > 54)
    {

        printInvalidTeamSize();
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

bool Mtmchkin::checkIfNameLegal(const string& name) {
    if (name.length() > 15) {
        printInvalidName();
        return false;
    }
    int currChar;
    for (char i : name) {
        currChar = int(i);
        if ((currChar > 122) || (currChar < 97 && currChar > 90) || (currChar < 65)) {
            printInvalidName();
            return false;
        }
    }
    return true;
}

bool Mtmchkin::checkClassIsLegal(const string& job){
    if (!(job == ROGUE || job == WIZARD || job == FIGHTER)) {
        printInvalidClass();
        return false;
    }
    return true;
}

void Mtmchkin::getInputPlayers() {
    for (int i = 0; i < m_teamSize; i++) {
        string input;
        std::getline(cin, input);
        int pos = input.find(" ");
        string name = input.substr(0, pos);
        string job = input.substr(pos + 1, input.length());
        bool illegal = !checkIfNameLegal(name) || !checkClassIsLegal(job);
        while (illegal) {
            std::getline(cin, input);
            pos = input.find(" ");
            name = input.substr(0, pos);
            job = input.substr(pos + 1, input.length());
            illegal = !checkIfNameLegal(name) || !checkClassIsLegal(job);
        }
        if (job == ROGUE)
        {
            m_players[i] = (unique_ptr<Player>(new Rogue(name)));
        }
        if (job == WIZARD)
        {
            m_players[i] = (unique_ptr<Player>(new Wizard(name)));
        }
        if (job == FIGHTER)
        {
            m_players[i] = (unique_ptr<Player>(new Fighter(name)));
        }
    }
}
