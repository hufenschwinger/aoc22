#ifndef BASTELKRAM_DAYFOURTYTWO_H
#define BASTELKRAM_DAYFOURTYTWO_H

#include "IDay.h"

namespace aoc22 {
    class DayFourtyTwo : public aoc22::IDay {
    public:
        DayFourtyTwo() = default;

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] std::string partOne() const override;

        [[nodiscard]] std::string partTwo() const override;

        ~DayFourtyTwo() = default;
    };
} // aoc22

#endif //BASTELKRAM_DAYFOURTYTWO_H
