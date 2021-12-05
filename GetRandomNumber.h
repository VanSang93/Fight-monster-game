#ifndef GETRANDOMNUMBER_H
#define GETRANDOMNUMBER_H
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

#endif