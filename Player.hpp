#pragma once

#include <string>
#include <vector>
#include "Game.hpp"

namespace coup
{

    class Player
    {
    protected:
        Game *game;
        std::string _name;
        int _coins;
        Action lastAction;

    protected:
        void checkTurn();

    public:
        Player(Game &game, std::string name);
        virtual void income();
        virtual void foreign_aid();
        virtual void coup(const Player &player);
        virtual int coins();
        virtual std::string role() = 0;
        friend std::ostream &operator<<(std::ostream &out, const Player &player);
    };

}
