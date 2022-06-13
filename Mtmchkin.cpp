#include "Mtmchkin.h"
#include <iostream>
using std::cin;
using std::string;
using std::unique_ptr;
// dosent know how to handle numbers bigger than the biggest int , check the option of unsigned int
// dosent know how to handle cases that start with an int and end with char like "3a"
void Mtmchkin::playRound()
{
    for (int i = 0; i <m_teamSize; i++)
    {
        m_cards.front()->applyEncounter(*(m_players[i]));
        unique_ptr<Card> temp;
        temp. m_cards.front();
        m_cards.push(m_cards.());

    }
}
void Mtmchkin::getInputTeamSize()
{

    printStartGameMessage();
    printEnterTeamSizeMessage();
    string choosen;
    std::getline(cin, choosen);
    while (choosen.length() != 1 || choosen[0] < 50 || choosen[0] > 54)
    {

        printInvalidTeamSize();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

void Mtmchkin::getInputPlayers()
{
    printInsertPlayerMessage();
    for (int i = 0; i < m_teamSize; i++)
    {
        string input = "";
        cin >> input;
        int pos = input.find(" ");
        string name = input.substr(0, pos);
        string job = input.substr(pos, input.length());
        // check name as well
        while (!(job == ROGUE || job == WIZARD || job == FIGHTER))
        {
            // if (cin.fail())
            // {
            //     printInvalidInput();
            //     cin.clear();
            //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // }
            // else
            // {
            printInvalidClass();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input = "";
            cin >> input;
            pos = input.find(" ");
            name = input.substr(0, pos);
            job = input.substr(pos, input.length());
            // }
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

int main()
{

    return 0;
}