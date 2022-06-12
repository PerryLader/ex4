#include "Merchant.h"
#include "../utilities.h"
using namespace std;

Merchant::Merchant() : Card()
{
}

void Merchant::applyEncounter(Player &player) const
{
    
    // need to be cheked
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(), player.getMoney());

    string choosen;
    std::getline(cin, choosen);
    while (choosen.length() != 1 || choosen[0] < 48 || choosen[0] > 50)
    {
        printInvalidInput();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::getline(cin, choosen);
    }
    int final = stoi(choosen);
    switch (final)
    {
    case 0:
        printMerchantSummary(cout, player.getName(), 0, 0);
        break;
    case 1:
        if (player.pay(5))
        {
            printMerchantSummary(cout, player.getName(), 1, 5);
        }
        break;
    case 2:
        if (player.pay(10))
        {
            printMerchantSummary(cout, player.getName(), 2, 10);
        }
        break;

    default:
        break;
    }
}
