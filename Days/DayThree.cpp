#include "DayThree.h"
#include <bitset>

using namespace aoc22;

DayThree::DayThree() : IDay("../Days/inputs/3.txt") {

}

uint8_t DayThree::number() const {
    return 3;
}

uint64_t DayThree::partOne() const {
    uint64_t sumOfPrios{0L};
    unsigned int half;
    std::bitset<52> leftItems;
    std::bitset<52> rightItems;
    std::bitset<52> overlap;
    for (const auto &line: lines) {
        half = line.length() / 2;
        const std::string_view& leftHalf{line.begin(), line.begin() + half};
        const std::string_view& rightHalf{line.begin() + half, line.end()};
        leftItems.reset();
        rightItems.reset();
        for (unsigned int i = 0; i < half; i++) {
            const char chL = leftHalf[i];
            leftItems.set(chL >= 'a' ? chL - 'a' : chL + 26 - 'A', true);
            const char chR = rightHalf[i];
            rightItems.set(chR >= 'a' ? chR - 'a' : chR + 26 - 'A', true);
        }
        overlap = leftItems & rightItems;
        for (uint8_t i = 0; i < 52; i++) {
            if (overlap[i]) {
                sumOfPrios += 1 + i;
                break;
            }
        }
    }
    return sumOfPrios;
}

uint64_t DayThree::partTwo() const {
    uint64_t sumOfBadgePrios = 0L;
    std::bitset<52> overlap;
    std::bitset<52> sacks[3];
    unsigned int groupCount = lines.size() / 3;
    for (unsigned int groupNumber = 0; groupNumber < groupCount; groupNumber++) {
        for(auto& set : sacks) {
            set.reset();
        }
        for (unsigned int memberNumber = 0; memberNumber < 3; memberNumber++) {
            std::string line = lines[3 * groupNumber + memberNumber];
            for (const char &ch: line) {
                sacks[memberNumber].set(ch >= 'a' ? ch - 'a' : ch + 26 - 'A', true);
            }
        }
        overlap = sacks[0] & sacks[1] & sacks[2];
        for (int i = 0; i < 52; i++) {
            if (overlap[i]) {
                sumOfBadgePrios += 1 + i;
            }
        }
    }
    return sumOfBadgePrios;
}
