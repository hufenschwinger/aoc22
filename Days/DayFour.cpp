#include "DayFour.h"

using namespace aoc22;

DayFour::DayFour() : IDay("../Days/inputs/4.txt") {

}

uint8_t DayFour::number() const {
    return 4;
}

uint64_t DayFour::partOne() const {
    uint64_t resultCounter = 0L;
    size_t comma, leftDash, rightDash;
    long leftStart, leftEnd, rightStart, rightEnd;
    for(auto& line : lines) {
        comma = line.find(',');
        leftDash = line.find('-');
        rightDash = line.find('-', leftDash + 1);

        leftStart = stol(line.substr(0, leftDash));
        leftEnd = stol(line.substr(leftDash + 1, comma - leftDash));

        rightStart = stol(line.substr(comma + 1, rightDash - comma));
        rightEnd = stol(line.substr(rightDash + 1));

        if ((leftStart <= rightStart && leftEnd >= rightEnd)
        || (rightStart <= leftStart && rightEnd >= leftEnd)) {
            resultCounter++;
        }
    }
    return resultCounter;
}

uint64_t DayFour::partTwo() const {
    uint64_t resultCounter = 0L;
    size_t comma, leftDash, rightDash;
    long leftStart, leftEnd, rightStart, rightEnd;
    for(auto& line : lines) {
        comma = line.find(',');
        leftDash = line.find('-');
        rightDash = line.find('-', leftDash + 1);

        leftStart = stol(line.substr(0, leftDash));
        leftEnd = stol(line.substr(leftDash + 1, comma - leftDash));

        rightStart = stol(line.substr(comma + 1, rightDash - comma));
        rightEnd = stol(line.substr(rightDash + 1));

        if ((leftStart <= rightStart && leftEnd >= rightStart)
        || (rightStart <= leftStart && rightEnd >= leftStart)) {
            resultCounter++;
        }
    }
    return resultCounter;
}
