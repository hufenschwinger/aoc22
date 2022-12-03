#include "DayThree.h"

using namespace aoc22;

DayThree::DayThree() : IDay("../Days/inputs/3.txt") {

}

uint8_t DayThree::number() const {
    return 3;
}

uint64_t DayThree::partOne() const {
    uint64_t sumOfPrios = 0L;
    std::string left, right;
    unsigned int half;
    for (const auto &line: lines) {
        half = line.length() / 2;
        uint8_t leftItems[52] = {0};
        uint8_t rightItems[52] = {0};
        for (unsigned int i = 0; i < half; i++) {
            char ch = line[i];
            int index;
            if (ch >= 'a') {
                index = ch - 'a';
            } else {
                index = ch + 26 - 'A';
            }
            leftItems[index] = 1;
        }
        for (unsigned int i = 0; i < half; i++) {
            char ch = line[i + half];
            int index;
            if (ch >= 'a') {
                index = ch - 'a';
            } else {
                index = ch + 26 - 'A';
            }
            rightItems[index] = 1;
        }
        for (uint8_t i = 0; i < 52; i++) {
            if (leftItems[i] != 0 && rightItems[i] != 0) {
                sumOfPrios += 1 + i;
                break;
            }
        }
    }
    return sumOfPrios;
}

uint64_t DayThree::partTwo() const {
    return 0;
}
