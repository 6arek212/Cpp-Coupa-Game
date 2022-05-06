#pragma once

#include "Player.hpp"

namespace coup
{

    class Captain : public Player
    {
    private:
    public:
        Captain(Game &game, std::string name) : Player(game, name){};
        void steal(Player &player);
        std::string role() const override;
        void block(Player &player);
    };

}
