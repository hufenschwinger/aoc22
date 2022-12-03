#include "DayThree.h"

using namespace aoc22;

DayThree::DayThree() : IDay("../Days/inputs/3.txt") {

}

uint8_t DayThree::number() const {
    return 3;
}

uint64_t DayThree::partOne() const {
    uint64_t sumOfPrios{0L};
    std::string left, right;
    unsigned int half;
    uint64_t leftItems;
    uint64_t rightItems;
    uint64_t overlap;
    for (const auto &line: lines) {
        half = line.length() / 2;
        leftItems = 0L;
        rightItems = 0L;
        for (unsigned int i = 0; i < half; i++) {
            char ch = line[i];
            int index;
            if (ch >= 'a') {
                index = ch - 'a';
            } else {
                index = ch + 26 - 'A';
            }
            leftItems |= (1 << index);
        }
        for (unsigned int i = 0; i < half; i++) {
            char ch = line[i + half];
            int index;
            if (ch >= 'a') {
                index = ch - 'a';
            } else {
                index = ch + 26 - 'A';
            }
            rightItems |= (1 << index);
        }
        overlap = leftItems & rightItems;
        for (uint8_t i = 0; i < 52; i++) {
            if (overlap & (1 << i)) {
                sumOfPrios += 1 + i;
                break;
            }
        }
    }
    return sumOfPrios;
}

uint64_t DayThree::partTwo() const {
    uint64_t sumOfBadgePrios = 0L;
    uint64_t overlap;
    unsigned int groupCount = lines.size() / 3;
    for (unsigned int groupNumber = 0; groupNumber < groupCount; groupNumber++) {
        uint64_t sacks[3] = {0};
        for (unsigned int memberNumber = 0; memberNumber < 3; memberNumber++) {
            std::string line = lines[3 * groupNumber + memberNumber];
            for (char &ch: line) {
                int index;
                if (ch >= 'a') {
                    index = ch - 'a';
                } else {
                    index = ch + 26 - 'A';
                }
                sacks[memberNumber] |= 1 << index;
            }
        }
        overlap = sacks[0] & sacks[1] & sacks[2];
        for (int i = 0; i < 52; i++) {
            if (overlap & (1 << i)) {
                sumOfBadgePrios += 1 + i;
            }
        }
    }
    return sumOfBadgePrios;
}
