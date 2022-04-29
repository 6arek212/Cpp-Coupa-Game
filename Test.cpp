#include "doctest.h"

#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace coup;
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void printPlayers(vector<Player *> args)
{
    cout << "----------------------" << endl;

    for (Player *p : args)
    {
        cout << *p << endl;
    }

    cout << "----------------------" << endl;
}

TEST_CASE("Check Actions Contessa/Ambassador/Captain")
{
    Game game;

    Captain captin{game, "Tarik"};
    Ambassador ambassador{game, "Wissam"};
    Contessa contessa{game, "Noa"};
    vector<string> players = game.players();

    CHECK_NOTHROW(captin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(contessa.income());

    CHECK_THROWS(contessa.block(ambassador));
    CHECK_THROWS(contessa.block(contessa));
    CHECK_THROWS(ambassador.block(captin));
    CHECK_THROWS(captin.block(contessa));

    CHECK_NOTHROW(captin.steal(contessa));
    CHECK_THROWS(captin.steal(ambassador));
    CHECK_THROWS(captin.foreign_aid());

    CHECK_THROWS(ambassador.transfer(contessa, captin));
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK(captin.coins() == 2);

    CHECK_NOTHROW(contessa.foreign_aid());

    CHECK_NOTHROW(captin.steal(contessa));
    CHECK(captin.coins() == 4);

    CHECK_NOTHROW(ambassador.block(captin));
    CHECK_THROWS(ambassador.block(captin));

    CHECK(captin.coins() == 2);
    CHECK(ambassador.coins() == 3);
    CHECK(contessa.coins() == 2);
}

TEST_CASE("Check Actions Duke/Assassin")
{
    Game game;

    Duke duke{game, "Tarik"};
    Assassin assassin{game, "Wissam"};
    vector<string> players = game.players();

    CHECK_NOTHROW(duke.tax());
    CHECK(duke.coins() == 3);
    CHECK_THROWS(duke.foreign_aid());
    CHECK_THROWS(duke.tax());
    CHECK_THROWS(duke.coup(assassin));
    CHECK_THROWS(duke.block(assassin));
    CHECK_THROWS(duke.income());
    CHECK_NOTHROW(assassin.foreign_aid());

    CHECK_THROWS(assassin.foreign_aid());
    CHECK_THROWS(assassin.coup(assassin));
    CHECK_THROWS(assassin.income());

    CHECK_THROWS(Duke(game, "W2"));
    CHECK_THROWS(game.winner());
    CHECK(game.turn() == duke.getName());

    CHECK_NOTHROW(duke.block(assassin));
    CHECK(assassin.coins() == 0);
    CHECK(duke.coins() == 3);
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.income());

    CHECK_NOTHROW(duke.income());
    CHECK_THROWS(duke.coup(assassin));
    CHECK_NOTHROW(assassin.foreign_aid());

    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.coup(duke));

    CHECK(assassin.coins() == 0);
    CHECK(duke.coins() == 8);

    CHECK(game.winner() == "Wissam");
}

TEST_CASE("Good Game")
{
    Game game;

    Duke duke{game, "Tarik"};
    Assassin assassin{game, "Wissam"};
    Ambassador ambassador{game, "Gia"};
    Captain captain{game, "Arik"};
    Contessa contessa{game, "Lior"};
    vector<Player *> p;
    vector<string> players = game.players();
    p.push_back(&duke);
    p.push_back(&assassin);
    p.push_back(&ambassador);
    p.push_back(&captain);
    p.push_back(&contessa);

    CHECK(players[0] == "Tarik");
    CHECK(players[1] == "Wissam");
    CHECK(players[2] == "Gia");
    CHECK(players[3] == "Arik");
    CHECK(players[4] == "Lior");

    /**
     * @brief
     *  duke 0
     *  assassin 0
     *  ambassador 0
     *  captain 0
     *  contessa 0
     */

    // printPlayers(p);

    duke.tax();
    assassin.foreign_aid();
    ambassador.income();
    captain.income();
    contessa.income();

    /**
     * @brief
     *  duke 3
     *  assassin 2
     *  ambassador 1
     *  captain 1
     *  contessa 1
     */
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 2);
    CHECK(ambassador.coins() == 1);
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 1);
    // printPlayers(p);

    duke.tax();
    assassin.foreign_aid();
    ambassador.income();
    captain.foreign_aid();
    contessa.foreign_aid();
    duke.block(contessa);

    /**
     * @brief
     *  duke 6
     *  assassin 4
     *  ambassador 2
     *  captain 3
     *  contessa 1
     */
    CHECK(duke.coins() == 6);
    CHECK(assassin.coins() == 4);
    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 3);
    CHECK(contessa.coins() == 1);

    // printPlayers(p);

    duke.tax();
    assassin.coup(contessa);
    ambassador.transfer(assassin, duke);
    captain.steal(ambassador);

    /**
     * @brief
     *  duke 10
     *  assassin 0
     *  ambassador 0
     *  captain 5
     *
     */
    CHECK(duke.coins() == 10);
    CHECK(assassin.coins() == 0);
    CHECK(ambassador.coins() == 0);
    CHECK(captain.coins() == 5);
    // printPlayers(p);

    duke.coup(assassin);
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 3
     *  ambassador 2
     *  captain 7
     *
     */
    CHECK(duke.coins() == 3);
    CHECK(ambassador.coins() == 2);
    CHECK(captain.coins() == 7);
    // printPlayers(p);

    duke.tax();
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 6
     *  ambassador 4
     *  captain 9
     *
     */
    CHECK(duke.coins() == 6);
    CHECK(ambassador.coins() == 4);
    CHECK(captain.coins() == 9);
    // printPlayers(p);

    duke.tax();
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 9
     *  ambassador 6
     *  captain 11
     *
     */
    CHECK(duke.coins() == 9);
    CHECK(ambassador.coins() == 6);
    CHECK(captain.coins() == 11);
    // printPlayers(p);

    duke.tax();
    ambassador.transfer(captain, duke);
    captain.coup(ambassador);

    /**
     * @brief
     *  duke 13
     *  captain 3
     *
     */
    CHECK(duke.coins() == 13);
    CHECK(captain.coins() == 3);
    // printPlayers(p);

    duke.coup(captain);

    /**
     * @brief
     *  duke 6
     *  captain 3
     *
     */
    CHECK(duke.coins() == 6);
    CHECK(captain.coins() == 3);
    /**
     * @brief
     *
     *  duke won !!
     *
     */

    // cout << "And the winner is : " << game.winner() << endl;
    CHECK(game.winner() == "Tarik");
}