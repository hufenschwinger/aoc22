#ifndef BASTELKRAM_DAYSIX_H
#define BASTELKRAM_DAYSIX_H

#include "IDay.h"

namespace aoc22 {

    class DaySix : public IDay<>{
    public:
        DaySix();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DaySix() = default;
    };

} // aoc22

#endif //BASTELKRAM_DAYSIX_H
