#include <iostream>
#include <memory>
#include <chrono>
#include "Days/IDay.h"
#include "Days/DayFourtyTwo.h"

void execute(std::unique_ptr<aoc22::IDay> iday) {
    const auto& number = iday->number();

    auto startOne = std::chrono::high_resolution_clock::now();
    const auto& solutionOne = iday->partOne();
    auto endOne = std::chrono::high_resolution_clock::now();
    auto durationOne = std::chrono::duration_cast<std::chrono::microseconds>(endOne - startOne).count();

    auto startTwo = std::chrono::high_resolution_clock::now();
    const auto& solutionTwo = iday->partTwo();
    auto endTwo = std::chrono::high_resolution_clock::now();
    auto durationTwo = std::chrono::duration_cast<std::chrono::microseconds>(endTwo - startTwo).count();

    std::cout << "Day: " << static_cast<int16_t>(number) << std::endl
              << "Part 1: " << solutionOne << " in " << durationOne << "us" << std::endl
              << "Part 2: " << solutionTwo << " in " << durationTwo << "us" << std::endl;
}

int main() {
    execute(std::make_unique<aoc22::DayFourtyTwo>());
    return 0;
}
