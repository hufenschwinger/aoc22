#include <bitset>
#include "DaySix.h"

using namespace aoc22;


DaySix::DaySix() : IDay("../Days/inputs/6.txt") {

}

uint8_t DaySix::number() const {
    return 6;
}

uint64_t DaySix::partOne() const {
    std::string line = lines[0];
    size_t counter{0};
    while (true) {
        std::bitset<26> uniques;
        for (int i = 0; i < 4; i++) {
            uniques.set(line[counter + i] - 'a', true);
        }
        if (uniques.count() == 4) {
            break;
        }
        counter++;
    }
    return counter + 4;
}

uint64_t DaySix::partTwo() const {
    std::string line = lines[0];
    size_t counter{0};
    while (true) {
        std::bitset<26> uniques;
        for (int i = 0; i < 14; i++) {
            uniques.set(line[counter + i] - 'a', true);
        }
        if (uniques.count() == 14) {
            break;
        }
        counter++;
    }
    return counter + 14;
}
