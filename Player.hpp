#pragma once

#include "Game.hpp"
#include <string>
#include <vector>

namespace coup
{
    class Player
    {
    public:
        static const int tenCoins = 10;
        static const int sevenCoins = 7;
        static const int threeCoins = 3;

    protected:
        Game *game;
        std::string _name;
        int _coins;
        int playerIndex;
        ActionOp lastAction;

    protected:
        void checkMustCoup();

    public:
        Player(Game &game, std::string &name);
        void income();
        void foreign_aid();
        int &coins();
        virtual void coup(Player &player);
        virtual std::string role() = 0;
        friend std::ostream &operator<<(std::ostream &out, const Player &player);

        int getPlayerIndex() const { return this->playerIndex; }
        void setPlayerIndex(int val) { this->playerIndex = val; }
        std::string getName() { return _name; }
        const ActionOp &getActionOp() const;
        void initAction();
        void checkTurn();
    };

}
