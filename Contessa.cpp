#include "Contessa.hpp"
using namespace coup;

std::string role()
{
    return "Contessa";
}

void block(const Player &player)
{
    if (player.lastAction != ASSASSINATE)
    {
        throw "Contessa can only block Assassiantion";
    }

    
}