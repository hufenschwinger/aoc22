#ifndef BASTELKRAM_IDAY_H
#define BASTELKRAM_IDAY_H

#include <string>

namespace aoc22 {
    class IDay {
    public:
        virtual const std::string partOne() const;
        virtual const std::string partTwo() const;
        virtual const uint8_t number() const;
        virtual ~IDay();
    };
} // aoc22

#endif //BASTELKRAM_IDAY_H
