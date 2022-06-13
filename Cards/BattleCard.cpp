#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"

BattleCard::BattleCard():
 Card()
{}
void Card::PrintCard(const Card& card) const 
{
    std::string name="check";
    const Dragon *dragon = dynamic_cast<const Dragon *>(&card);
    if (dragon != nullptr)
    {
        // player is a dragon
        name=DRAGON;
        printCardDetails(std::cout,name);
        printMonsterDetails(std::cout,DRAGON_FORCE,DRAGON_HP,DRAGON_LOOT,true);
    }

    const Vampire *vampire = dynamic_cast<const Vampire *>(&card);
    if (vampire != nullptr)
    {
        // player is a vampire
        name=VAMPIRE;
        printCardDetails(std::cout,name);
        printMonsterDetails(std::cout,VAMPIRE_FORCE,VAMPIRE_HP,VAMPIRE_LOOT,false);
    }

    const Goblin *goblin = dynamic_cast<const Goblin *>(&card);
    if (goblin != nullptr)
    {
        // player is a goblin
        name=GOBLIN;
        printCardDetails(std::cout,name);
        printMonsterDetails(std::cout,GOBLIN_FORCE,GOBLIN_HP,GOBLIN_LOOT,false);
    }
    
    if(name=="check")
    {
        std::cout<<"errroorrr";
    }
    
    printEndOfCardDetails(std::cout);

}