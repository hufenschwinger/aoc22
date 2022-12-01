#ifndef BASTELKRAM_IDAY_H
#define BASTELKRAM_IDAY_H

#include <string>
#include <vector>
#include <fstream>

namespace aoc22 {
    class IDay {
    public:
        [[nodiscard]] virtual uint8_t number() const = 0;

        [[nodiscard]] virtual uint64_t partOne() const = 0;

        [[nodiscard]] virtual uint64_t partTwo() const = 0;

        virtual ~IDay() = default;

    protected:
        [[nodiscard]] static std::vector<std::string> readFile(const std::string& name) {
            std::ifstream file(name);
            std::string str;
            std::vector<std::string> result;
            while (std::getline(file, str)) {
                result.push_back(str);
            }
            return result;
        }
    };
} // aoc22

#endif //BASTELKRAM_IDAY_H
