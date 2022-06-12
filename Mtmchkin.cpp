#include "Mtmchkin.h"
#include <iostream>
using namespace std;

// dosent know how to handle numbers bigger than the biggest int , check the option of unsigned int
// dosent know how to handle cases that start with an int and end with char like "3a"

void Mtmchkin::getInputTeamSize()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int teamSize = 0;
    while (cin >> teamSize && teamSize > 6 || teamSize < 2)
    {
        if (cin.fail())
        {
            printInvalidInput();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            printInvalidTeamSize();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    m_teamSize = teamSize;
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
        while (!(job == ROGUE || job == MAGE || job == FIGHTER))
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            input = "";
            cin >> input;
            pos = input.find(" ");
            name = input.substr(0, pos);
            job = input.substr(pos, input.length());
            // }
        }
        if (job == ROGUE)
        {
            Players.push(unique_ptr<Player>(new Rogue(name)));
        }
        if (job == MAGE)
        {
            Players.push(unique_ptr<Player>(new Mage(name)));
        }
        if (job == FIGHTER)
        {
            Players.push(unique_ptr<Player>(new Fighter(name)));
        }
    }
}

int main()
{

    return 0;
}