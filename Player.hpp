#pragma once

#include "Game.hpp"
#include <string>
#include <vector>

namespace coup
{
    class ActionOp
    {

    public:
        Action action;
        Player *on1;
        Player *on2;
        ActionOp(Action action = NONE, Player *on1 = NULL, Player *on2 = NULL)
        {
            this->action = action;
            this->on1 = on1;
            this->on2 = on2;
        }
    };

    class Player
    {
    public:
        static std::vector<Player &> players;
        ActionOp lastAction{NONE};
        int playerIndex;
        std::string _name;

    protected:
        Game *game;
        int _coins;
        bool isCouped;

    protected:
        void checkTurn();
        void checkMustCoup();

    public:
        Player(Game &game, std::string name);
        void income();
        void foreign_aid();
        void coup(Player &player);
        int &coins();
        virtual std::string role() = 0;
        friend std::ostream &operator<<(std::ostream &out, const Player &player);
        const ActionOp &getActionOp() const;
        void Player::updateIndexs();
        void setIsCouped(bool val) { isCouped = val; }
    };

}
