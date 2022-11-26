#include "DayFourtyTwo.h"
#include "IDay.h"


namespace aoc22 {
    uint8_t IDay::number() const {
        return 42;
    }

    std::string IDay::partOne() const {
        return "Teil 1";
    }

    std::string IDay::partTwo() const {
        return "Teil 2";
    }

    IDay::~IDay() = default;

    DayFourtyTwo::~DayFourtyTwo() = default;
} // aoc22