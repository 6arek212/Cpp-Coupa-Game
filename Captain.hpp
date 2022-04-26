#include "Player.hpp"

namespace coup
{

    class Captain : public Player
    {
    private:
    public:
        Captain(Game &game, std::string name);
        void steal(Player &player);
        std::string role() override;
        void block(const Player &player);
    };

}
