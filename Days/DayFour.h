#ifndef BASTELKRAM_DAYFOUR_H
#define BASTELKRAM_DAYFOUR_H

#include "IDay.h"

namespace aoc22 {

    class DayFour : public aoc22::IDay {
    public:
        DayFour();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayFour() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYFOUR_H
