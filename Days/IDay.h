#ifndef BASTELKRAM_IDAY_H
#define BASTELKRAM_IDAY_H

#include <string>
#include <vector>
#include <fstream>

namespace aoc22 {

    template<typename T = uint64_t>
    class IDay {
    public:
        explicit IDay(const std::string &fileName) {
            lines = readFile(fileName);
            firstLine = lines[0];
        }

        [[nodiscard]] virtual uint8_t number() const = 0;

        [[nodiscard]] virtual T partOne() const = 0;

        [[nodiscard]] virtual T partTwo() const = 0;

        virtual ~IDay() = default;

    protected:
        std::vector<std::string> lines;
        std::string firstLine;

    private:
        [[nodiscard]] static std::vector<std::string> readFile(const std::string &name) {
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
