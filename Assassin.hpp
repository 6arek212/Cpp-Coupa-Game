#include "Player.hpp"

namespace coup
{

    class Assassin : public Player
    {
    private:
    public:
        Assassin(Game &game, std::string name) : Player(game, name){};
        void assassinate(Player &player);
        std::string role() override;
    };

}
