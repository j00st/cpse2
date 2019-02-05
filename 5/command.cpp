#include "command.hpp"

command::command(uint_fast8_t player, const uint_fast8_t place) :
    player(player),
    place(place)
{}

uint_fast8_t command::getPlayer() {
    return player;
}

uint_fast8_t command::getPlace() {
    return place;
}
