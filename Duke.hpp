#include "Player.hpp"
#include <string>

namespace coup
{

    class Duke : public Player
    {
    private:
    public:
        Duke(Game &game, std::string name) : Player(game, name){};
        void tax();
        std::string role() override;
        void block(Player &player);
    };

}
