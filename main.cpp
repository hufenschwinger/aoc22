#include <iostream>
#include "Days/IDay.h"

int main() {
    //TODO instantiate and execute days
    return 0;
}

void execute(const aoc22::IDay *iday) {
    //TODO measure
    const uint8_t number = iday->number();
    const std::string solutionOne = iday->partOne();
    const std::string solutionTwo = iday->partTwo();
    std::cout << "day " << number << std::endl
              << "Part 1" << solutionOne << std::endl
              << "Part 2" << solutionTwo << std::endl;
}
