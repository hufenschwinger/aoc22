
#ifndef BASTELKRAM_DAYTWO_H
#define BASTELKRAM_DAYTWO_H

#include <cstdint>
#include "IDay.h"

namespace aoc22 {

    class DayTwo : public aoc22::IDay<> {
    public:
        DayTwo();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayTwo() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYTWO_H
