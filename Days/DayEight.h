#ifndef BASTELKRAM_DAYEIGHT_H
#define BASTELKRAM_DAYEIGHT_H

#include <memory>
#include <iostream>
#include "IDay.h"

namespace aoc22 {
    class Tree {
    public:
        Tree() = default;

        uint8_t x, y, z;
        bool topVisible, bottomVisible, leftVisible, rightVisible, isEdge;

        inline bool isVisible() const { return isEdge || topVisible || bottomVisible || leftVisible || rightVisible; }
    };


    class DayEight : public aoc22::IDay<> {
    public:
        DayEight();

        [[nodiscard]] uint8_t number() const override;

        [[nodiscard]] uint64_t partOne() const override;

        [[nodiscard]] uint64_t partTwo() const override;

        ~DayEight() = default;

    private:
        Tree *parse(size_t *w, size_t *h) const;
    };

} // aoc22

#endif //BASTELKRAM_DAYEIGHT_H
