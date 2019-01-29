#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "gameController.hpp"

class command {
public:

    command(uint_fast8_t player = 0, const uint_fast8_t place = 0);

private:

    uint_fast8_t player;
    const uint_fast8_t place;

};

#endif // COMMAND_HPP
