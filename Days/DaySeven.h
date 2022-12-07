#ifndef BASTELKRAM_DAYSEVEN_H
#define BASTELKRAM_DAYSEVEN_H

#include "IDay.h"

namespace aoc22 {

    class Directory {
    public:
        explicit Directory(std::shared_ptr<Directory> parent);
        std::shared_ptr<Directory> parent;
        std::vector<std::shared_ptr<Directory>> children{};
        uint64_t size{0};
        ~Directory() = default;
    };

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
