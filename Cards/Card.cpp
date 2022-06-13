#include "Card.h"
#include "Barfight.h"
#include "Fairy.h"
#include "Merchant.h"
#include "Pitfall.h"
#include "Treasure.h"


 void Card::PrintCard(const Card& card) const
{
    std::string name="check";
    const Barfight *barfight = dynamic_cast<const Barfight *>(&card);
    if (barfight != nullptr)
    {
        // player is a barfight
        name=BARFIGHT;
    }

    const Fairy *fairy = dynamic_cast<const Fairy *>(&card);
    if (fairy != nullptr)
    {
        // player is a Fairy
        name=FAIRY;
    }

    const Merchant *merchant = dynamic_cast<const Merchant *>(&card);
    if (merchant != nullptr)
    {
        // player is a merchant
        name=MERCHANT;
    }

    const Pitfall *pitfall = dynamic_cast<const Pitfall *>(&card);
    if (pitfall != nullptr)
    {
        // player is a pitfall
        name=PITFALL;
    }

    const Treasure *treasure = dynamic_cast<const Treasure *>(&card);
    if (treasure != nullptr)
    {
        // player is a treasure
        name=TREASURE;
    }

    if(name=="check")
    {
        std::cout<<"errroorrr";
    }
    printCardDetails(std::cout,name);
    printEndOfCardDetails(std::cout);
}

