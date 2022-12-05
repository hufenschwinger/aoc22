#ifndef BASTELKRAM_DAYFIVE_H
#define BASTELKRAM_DAYFIVE_H

#include "IDay.h"

namespace aoc22 {

    class DayFive : public aoc22::IDay<std::string> {
    public:
        DayFive();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] std::string partOne() const override;

        [[nodiscard]] std::string partTwo() const override;

        ~DayFive() = default;
    };
} // aoc22

#endif //BASTELKRAM_DAYFIVE_H
