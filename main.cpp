#include <iostream>
#include <memory>
#include "Days/IDay.h"
#include "Days/DayFourtyTwo.h"

void execute(std::unique_ptr<aoc22::IDay> iday) {
    //TODO measure executions
    const auto& number = iday->number();
    const auto& solutionOne = iday->partOne();
    const auto& solutionTwo = iday->partTwo();
    std::cout << "Day: " << number << std::endl
              << "Part 1: " << solutionOne << std::endl
              << "Part 2: " << solutionTwo << std::endl;
}

int main() {
    execute(std::make_unique<aoc22::DayFourtyTwo>());
    return 0;
}
