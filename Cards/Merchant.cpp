#include "Merchant.h"
#include "../utilities.h"
using std::cin;
using std::cout;
using std::string;

Merchant::Merchant() : Card(MERCHANT)
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
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(cin, choosen);
    }
    int final;
    try
    {
        final = stoi(choosen);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    switch (final)
    {
    case DONT_BUY:
        printMerchantSummary(cout, player.getName(), DONT_BUY, DONT_BUY);
        break;
    case BUY_HEAL:
        if (player.pay(PRICE_HEAL))
        {
            player.heal(DEF_HEAL);
<<<<<<< HEAD
            printMerchantSummary(cout, player.getName(), BUY_HEAL, PRICE_HEAL);
=======
        printMerchantSummary(cout, player.getName(), BUY_HEAL, PRICE_HEAL);

>>>>>>> 2addc046132c2c6a6b9cdf759d26433c4ce29aec
        }
        else
        {
            printMerchantInsufficientCoins(cout);
            printMerchantSummary(cout, player.getName(), BUY_HEAL, DONT_BUY);
        }
        break;
    case BUY_FORCE:
        if (player.pay(PRICE_FORCE))
        {
            player.buff(DEF_BUFF);
<<<<<<< HEAD
            printMerchantSummary(cout, player.getName(), BUY_FORCE, PRICE_FORCE);
=======
        printMerchantSummary(cout, player.getName(), BUY_FORCE, PRICE_FORCE);

>>>>>>> 2addc046132c2c6a6b9cdf759d26433c4ce29aec
        }
        else
        {
            printMerchantInsufficientCoins(cout);
<<<<<<< HEAD
            printMerchantSummary(cout, player.getName(), BUY_FORCE, DONT_BUY);
=======
        printMerchantSummary(cout, player.getName(), BUY_FORCE, DONT_BUY);

>>>>>>> 2addc046132c2c6a6b9cdf759d26433c4ce29aec
        }
        break;
    default:
        cout << "fuck it";
        break;
    }
}
