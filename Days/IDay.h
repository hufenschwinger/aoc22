#ifndef BASTELKRAM_IDAY_H
#define BASTELKRAM_IDAY_H

#include <string>

namespace aoc22 {
    class IDay {
    public:
        [[nodiscard]] virtual uint8_t  number() const;

        [[nodiscard]] virtual std::string partOne() const;

        [[nodiscard]] virtual std::string partTwo() const;
    };
} // aoc22

#endif //BASTELKRAM_IDAY_H
