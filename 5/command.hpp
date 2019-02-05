#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <functional>

class command {
public:

    command(uint_fast8_t player = 0, const uint_fast8_t place = 0);
    uint_fast8_t getPlayer();
    uint_fast8_t getPlace();

private:

    uint_fast8_t player;
    const uint_fast8_t place;

};

#endif // COMMAND_HPP
