#include "Player.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace coup
{
    Player::Player(Game &game, std::string name)
    {
        this->_coins = 0;
        this->_name = name;
        this->game = &game;
        this->isCouped = false;
        playerIndex = this->game->addPlayer(name);
        this->players.push_back(*this);
    }

    void Player::checkTurn()
    {
        if (this->game->getTurnIndex() != this->playerIndex)
        {
            throw "Error its not your turn";
        }
    }

    void Player::checkMustCoup()
    {
        if (this->_coins >= 10)
        {
            throw "You have more than 10 coins you must coup !";
        }
    }

    void Player::income()
    {
        checkTurn();
        checkMustCoup();
        this->_coins++;
        lastAction = ActionOp(INCOME);
        game->endTurn();
    }

    void Player::foreign_aid()
    {
        checkTurn();
        checkMustCoup();
        this->_coins += 2;
        lastAction = ActionOp(FOREIGN_AID);
        game->endTurn();
    }

    void Player::updateIndexs()
    {
        int cnt = 0;
        for (Player &p : players)
        {
            if (!p.isCouped)
            {
                p.playerIndex = cnt;
            }
        }
    }

    void Player::coup(Player &player)
    {
        checkTurn();
        if (_coins < 7)
        {
            throw "Error cant coup , you need at least 7 coins !";
        }
        _coins -= 7;
        lastAction = ActionOp(COUP, &player);
        player.isCouped = true;
        updateIndexs();
        game->endTurn();
    }

    int &Player::coins()
    {
        return _coins;
    }

    const ActionOp &Player::getActionOp() const
    {
        return lastAction;
    }

    std::ostream &operator<<(std::ostream &out, const Player &player)
    {
        out << "Player: name: " << player._name << " "
            << "coins : " << player._coins << std::endl;
    }
}