#pragma once

#include "Player.hpp"
#include <string>

namespace coup
{

    class Contessa : public Player
    {
    private:
    public:
        Contessa(Game &game, std::string name) : Player(game, name){};
        std::string role() const override;
        void block(Player &player);
    };

}
