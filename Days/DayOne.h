#ifndef BASTELKRAM_DAYONE_H
#define BASTELKRAM_DAYONE_H

#include "IDay.h"

namespace aoc22 {

    class DayOne : public aoc22::IDay<> {
    public:
        DayOne();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayOne() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYONE_H
