#ifndef BASTELKRAM_DAYFORTYTWO_H
#define BASTELKRAM_DAYFORTYTWO_H

#include "IDay.h"

namespace aoc22 {
    class DayFortyTwo : public aoc22::IDay {
    public:
        DayFortyTwo() = default;

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayFortyTwo() = default;
    };
} // aoc22

#endif //BASTELKRAM_DAYFORTYTWO_H
