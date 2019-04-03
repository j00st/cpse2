#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <functional>

class command {
public:

    command(int player = 0, const int place = 0);
    int getPlayer();
    int getPlace();

private:

    int player;
    const int place;

};

#endif // COMMAND_HPP
