#include "command.hpp"

command::command(int player, const int place) :
    player(player),
    place(place)
{}

int command::getPlayer() {
    return player;
}

int command::getPlace() {
    return place;
}
