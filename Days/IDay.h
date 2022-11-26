#ifndef BASTELKRAM_IDAY_H
#define BASTELKRAM_IDAY_H

#include <string>

namespace aoc22 {
    class IDay {
    public:
        [[nodiscard]] virtual uint8_t number() const = 0;

        [[nodiscard]] virtual std::string partOne() const = 0;

        [[nodiscard]] virtual std::string partTwo() const = 0;

        virtual ~IDay() = default;
    };
} // aoc22

#endif //BASTELKRAM_IDAY_H
