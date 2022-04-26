#include "Player.hpp"
#include <string>
using namespace coup;
using namespace std;

Player::Player(Game &game, std::string name)
{
    this->_name = name;
    this->game = &game;
    game.addPlayer(name);
}

void Player::checkTurn()
{
    if (this->game->turn() != this->_name)
    {
        throw "Error its not your turn";
    }
}

void Player::income()
{
    checkTurn();
    this->_coins++;
    lastAction = INCOME;
    game->endTurn();
}

void Player::foreign_aid()
{
    checkTurn();
    this->_coins += 2;
    lastAction = FOREIGN_AID;
    game->endTurn();
}

void Player::coup(const Player &player)
{
    checkTurn();
    if (_coins < 7)
    {
        throw "Error cant coup , you need at least 7 coins !";
    }

    _coins -= 7;
    game->deletePlayer(player._name);
    lastAction = COUP;
    game->endTurn();
}

int Player::coins()
{
    return _coins;
}