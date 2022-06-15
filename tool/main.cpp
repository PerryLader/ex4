#include <iostream>
#include "Mtmchkin.h"
using std::cin;
using std::string;
int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    Mtmchkin game("deck.txt");
    while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
    {
        game.playRound();
    }
    game.printLeaderBoard();

    return 0;
}