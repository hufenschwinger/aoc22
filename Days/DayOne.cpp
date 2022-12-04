#include <numeric>
#include "DayOne.h"

using namespace aoc22;

DayOne::DayOne() : IDay("../Days/inputs/1.txt") {

}

uint8_t DayOne::number() const {
    return 1;
}

uint64_t DayOne::partOne() const {
    long currentCounter{0L};
    long max{0L};

    for (const auto &line: lines) {
        if (!line.empty()) {
            currentCounter += std::stol(line);
            continue;
        }
        if (currentCounter > max) {
            max = currentCounter;
        }
        currentCounter = 0L;
    }
    return max;
}

uint64_t DayOne::partTwo() const {
    long currentCounter{0L};
    std::vector<long> sums{0L};

    for (const auto &line: lines) {
        if (!line.empty()) {
            currentCounter += std::stol(line);
            continue;
        }
        sums.push_back(currentCounter);
        currentCounter = 0L;
    }
    std::sort(sums.rbegin(), sums.rend());
    return std::accumulate(sums.begin(), sums.begin() + 3, 0);
}