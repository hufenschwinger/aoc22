#ifndef BASTELKRAM_DAYFIVE_H
#define BASTELKRAM_DAYFIVE_H

#include "IDay.h"

namespace aoc22 {

    class DayFive : public aoc22::IDay {
    public:
        DayFive();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayFive() = default;
    };
} // aoc22

#endif //BASTELKRAM_DAYFIVE_H
