#include <stack>
#include <iostream>
#include "DayFive.h"

using namespace aoc22;

DayFive::DayFive() : IDay("../Days/inputs/5.txt") {

}

uint8_t DayFive::number() const {
    return 5;
}

std::string DayFive::partOne() const {
    size_t emptyLine = -1;
    for (std::vector<int>::size_type i = 0;
         i != lines.size(); i++) { //find line separating initial state from instructions
        if (lines[i].empty()) {
            emptyLine = i;
            break;
        }
    }
    std::stack<char> piles[9];
    for (int64_t i = emptyLine - 2; i >= 0; i--) {
        std::string line = lines[i];
        size_t len = line.length();
        size_t itemsInLine = (len + 1) >> 2;
        for (size_t stackIndex = 0; stackIndex < itemsInLine; stackIndex++) {
            char item = line[1 + stackIndex * 4];
            if (item == ' ') {
                continue;
            }
            piles[stackIndex].push(item);
        }
    }

    for (size_t movementIndex = emptyLine + 1; movementIndex < lines.size(); movementIndex++) {
        std::string movement = lines[movementIndex];
        int amount, from, to;

        if (movement.length() == 18) {
            amount = std::stoi(movement.substr(5, 1));
            from = std::stoi(movement.substr(12, 1)) - 1;
            to = std::stoi(movement.substr(17, 1)) - 1;
        } else {
            amount = std::stoi(movement.substr(5, 2));
            from = std::stoi(movement.substr(13, 1)) - 1;
            to = std::stoi(movement.substr(18, 1)) - 1;
        }

        for (int count = 0; count < amount; count++) {
            char crate = piles[from].top();
            piles[from].pop();
            piles[to].push(crate);
        }
    }
    std::string result;

    for (auto &pile: piles) {
        result += (!pile.empty() ? pile.top() : ' ');
    }
    return result;
}

std::string DayFive::partTwo() const {
    size_t emptyLine = -1;
    for (std::vector<int>::size_type i = 0;
         i != lines.size(); i++) { //find line separating initial state from instructions
        if (lines[i].empty()) {
            emptyLine = i;
            break;
        }
    }
    std::stack<char> piles[9];
    for (int64_t i = emptyLine - 2; i >= 0; i--) {
        std::string line = lines[i];
        size_t len = line.length();
        size_t itemsInLine = (len + 1) >> 2;
        for (size_t stackIndex = 0; stackIndex < itemsInLine; stackIndex++) {
            char item = line[1 + stackIndex * 4];
            if (item == ' ') {
                continue;
            }
            piles[stackIndex].push(item);
        }
    }

    for (size_t movementIndex = emptyLine + 1; movementIndex < lines.size(); movementIndex++) {
        std::string movement = lines[movementIndex];
        int amount, from, to;

        if (movement.length() == 18) {
            amount = std::stoi(movement.substr(5, 1));
            from = std::stoi(movement.substr(12, 1)) - 1;
            to = std::stoi(movement.substr(17, 1)) - 1;
        } else {
            amount = std::stoi(movement.substr(5, 2));
            from = std::stoi(movement.substr(13, 1)) - 1;
            to = std::stoi(movement.substr(18, 1)) - 1;
        }
        std::stack<char> sidePile;
        for (int count = 0; count < amount; count++) {
            char crate = piles[from].top();
            piles[from].pop();
            sidePile.push(crate);
        }
        for (int count = 0; count < amount; count++) {
            char crate = sidePile.top();
            sidePile.pop();
            piles[to].push(crate);
        }
    }
    std::string result;

    for (auto &pile: piles) {
        result += (!pile.empty() ? pile.top() : ' ');
    }
    return result;
}
