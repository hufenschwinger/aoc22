#include <iostream>
#include <functional>
#include "Days/IDay.h"
#include "Days/DayFourtyTwo.h"

void execute(const std::function<aoc22::IDay*(void)>& supplier) {
    //TODO measure executions
    const aoc22::IDay *iday = supplier();
    const uint8_t number = iday->number();
    const std::string solutionOne = iday->partOne();
    const std::string solutionTwo = iday->partTwo();
    std::cout << "Day: " << number << std::endl
              << "Part 1: " << solutionOne << std::endl
              << "Part 2: " << solutionTwo << std::endl;
    delete iday;
}

int main() {
    execute([]() -> aoc22::DayFourtyTwo* {return new aoc22::DayFourtyTwo();});
    return 0;
}
