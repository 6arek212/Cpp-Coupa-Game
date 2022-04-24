#include "Player.hpp"
using namespace coup;
#include <string>
using namespace std;

Player::Player(string name)
{
    this->_name = name;
}

void Player::income()
{
    this->_coins++;
}

void Player::foreign_aid()
{
}

void Player::coup()
{
}

int Player::coins()
{
}

int Player::role()
{
}