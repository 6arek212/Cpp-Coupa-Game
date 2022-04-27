#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include <iostream>
namespace coup
{

    void Game::hasPlayers() const
    {
        if (_players.size() == 0)
        {
            throw "Error no players !";
        }
    }

    bool compareFun(Player *p1, Player *p2)
    {
        return p1->getPlayerIndex() < p2->getPlayerIndex();
    }

    void Game::couped(Player *p2)
    {
        Player *temp = _players[(size_t)_turn];
        int index = _turn;

        _players.erase(std::remove(_players.begin(), _players.end(), p2), _players.end());

        if (temp != _players[(size_t)_turn])
        {
            _turn = (--_turn) % (int)_players.size();
        }
    }

    void Game::uncoup(Player *p2)
    {
        Player *temp = _players[(size_t)_turn];
        int index = _turn;

        _players.push_back(p2);
        std::sort(_players.begin(), _players.end(), compareFun);

        if (temp != _players[(size_t)_turn])
        {
            _turn = (++_turn) % (int)_players.size();
        }
    }

    void Game::addPlayer(Player &player)
    {
        if (_turn == -1)
            _turn = 0;
        _players.push_back(&player);
        player.setPlayerIndex(_players.size() - 1);
    }

    bool Game::isItMyTurn(Player &player)
    {
        hasPlayers();
        if (_players[(size_t)_turn] != &player)
        {
            return false;
        }
        return true;
    }

    void Game::endTurn(Player *p)
    {
        p->checkTurn();
        hasPlayers();
        _turn = (_turn + 1) % (int)_players.size();
    }

    std::vector<std::string> Game::players() const
    {
        std::vector<std::string> p;
        for (Player *player : _players)
        {
            p.push_back(player->getName());
        }
        return p;
    }

    std::string Game::turn()
    {
        hasPlayers();
        return _players[(size_t)_turn]->getName();
    }

    std::string Game::winner() const
    {
        hasPlayers();
        if (_players.size() > 1)
        {
            throw "Error the game is still alive";
        }
        return _players[0]->getName();
    }
}