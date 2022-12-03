#ifndef BASTELKRAM_DAYTHREE_H
#define BASTELKRAM_DAYTHREE_H

#include "IDay.h"

namespace aoc22 {

    class DayThree : public aoc22::IDay {
    public:
        DayThree();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayThree() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYTHREE_H
