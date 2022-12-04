#include "DayTwo.h"

using namespace aoc22;

DayTwo::DayTwo() : IDay("../Days/inputs/2.txt") {

}

uint8_t DayTwo::number() const {
    return 2;
}

const uint8_t points1[3][3] = {
        {4, 8, 3},
        {1, 5, 9},
        {7, 2, 6}
};

uint64_t DayTwo::partOne() const {
    uint64_t sumOfPoints{0L};
    for (const auto& line : lines) {
        sumOfPoints += points1[(line[0] - 'A')][(line[2] - 'X')];
    }
    return sumOfPoints;
}

const uint8_t points2[3][3] = {
        {3, 4, 8},
        {1, 5, 9},
        {2, 6, 7}
};

uint64_t DayTwo::partTwo() const {
    uint64_t sumOfPoints{0L};
    for (const auto& line : lines) {
        sumOfPoints += points2[(line[0] - 'A')][(line[2] - 'X')];
    }
    return sumOfPoints;
}