#ifndef BASTELKRAM_DAYSEVEN_H
#define BASTELKRAM_DAYSEVEN_H

#include "IDay.h"

namespace aoc22 {

class DaySeven : public aoc22::IDay<> {
public:
    DaySeven();

    [[nodiscard]] uint8_t number() const override;

    [[nodiscard]] uint64_t partOne() const override;

    [[nodiscard]] uint64_t partTwo() const override;

    ~DaySeven() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYSEVEN_H
