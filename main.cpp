#include <iostream>
#include <memory>
#include <chrono>
#include "Days/IDay.h"
#include "Days/DayOne.h"
#include "Days/DayTwo.h"
#include "Days/DayThree.h"
#include "Days/DayFour.h"
#include "Days/DayFive.h"
#include "Days/DaySix.h"
#include "Days/DaySeven.h"
#include "Days/DayEight.h"

template<typename T>
[[nodiscard]] std::string format(T result) {
    return std::to_string(result);
}

template<>
[[maybe_unused]] [[nodiscard]] std::string format(std::string result) {
    return result;
}

template <typename T>
void execute(std::unique_ptr<aoc22::IDay<T>> day) {
    const auto& number = day->number();

    const auto startOne = std::chrono::high_resolution_clock::now();
    const T& solutionOne = day->partOne();
    const auto endOne = std::chrono::high_resolution_clock::now();
    const auto durationOne = std::chrono::duration_cast<std::chrono::microseconds>(endOne - startOne).count();

    const auto startTwo = std::chrono::high_resolution_clock::now();
    const auto& solutionTwo = day->partTwo();
    const auto endTwo = std::chrono::high_resolution_clock::now();
    const auto durationTwo = std::chrono::duration_cast<std::chrono::microseconds>(endTwo - startTwo).count();

    std::cout << "Day " << static_cast<int16_t>(number) << ": "
              << "Part 1: " << format<T>(solutionOne) << " in " << durationOne << "us, "
              << "Part 2: " << format<T>(solutionTwo) << " in " << durationTwo << "us" << "\n";
}

int main() {
    execute<uint64_t>(std::make_unique<aoc22::DayOne>());
    execute<uint64_t>(std::make_unique<aoc22::DayTwo>());
    execute<uint64_t>(std::make_unique<aoc22::DayThree>());
    execute<uint64_t>(std::make_unique<aoc22::DayFour>());
    execute<std::string>(std::make_unique<aoc22::DayFive>());
    execute<uint64_t>(std::make_unique<aoc22::DaySix>());
    execute<uint64_t>(std::make_unique<aoc22::DaySeven>());
    execute<uint64_t>(std::make_unique<aoc22::DayEight>());
    return 0;
}
