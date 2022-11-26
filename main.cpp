#include <iostream>
#include "Days/IDay.h"
#include "Days/DayFourtyTwo.h"

void execute(const aoc22::IDay *iday) { //TODO maybe supplier as param?
    //TODO measure
    const uint8_t number = iday->number();
    const std::string solutionOne = iday->partOne();
    const std::string solutionTwo = iday->partTwo();
    std::cout << "Day: " << number << std::endl
              << "Part 1: " << solutionOne << std::endl
              << "Part 2: " << solutionTwo << std::endl;
}

int main() {
    aoc22::IDay *day = new aoc22::DayFourtyTwo();
    execute(day);
    delete day;
    return 0;
}
