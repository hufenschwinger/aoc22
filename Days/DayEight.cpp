#include "DayEight.h"

using namespace aoc22;

DayEight::DayEight() : IDay("../Days/inputs/8.txt") {

}

uint8_t DayEight::number() const {
    return 8;
}

uint64_t DayEight::partOne() const {
    size_t width, height;
    auto forest = parse(&width, &height, true);
    Tree *current;
    uint32_t maxHeight;

    //left edge
    for (auto currentRow{1}; currentRow < (height - 1); currentRow++) {//row 1 -> e-1
        maxHeight = (forest + (width * currentRow))->z; //init on (r|0)
        for (auto currentColumn{1}; currentColumn < (width - 1); currentColumn++) {//column 1 -> e-1
            current = forest + (width * currentRow + currentColumn);
            if (maxHeight >= current->z) {
                current->leftVisible = false;
            } else {
                maxHeight = current->z;
            }
        }
    }
    //right edge
    maxHeight = 0;
    for (auto currentRow{1}; currentRow < (height - 1); currentRow++) {//row 1 -> e-1
        maxHeight = (forest + (width * (currentRow + 1) - 1))->z; //init on (r|e)
        for (auto currentColumn = width - 2; currentColumn > 0; currentColumn--) { //column e-1 -> 1
            current = forest + (width * currentRow + currentColumn);
            if (maxHeight >= current->z) {
                current->rightVisible = false;
            } else {
                maxHeight = current->z;
            }
        }
    }
    //top edge
    for (auto currentColumn{1}; currentColumn < (width - 1); currentColumn++) {//column 1 -> e-1
        maxHeight = (forest + currentColumn)->z; //init on (0|c)
        for (auto currentRow{1}; currentRow < height - 1; currentRow++) { //row 1 -> e-1
            current = forest + (width * currentRow + currentColumn);
            if (maxHeight >= current->z) {
                current->topVisible = false;
            } else {
                maxHeight = current->z;
            }
        }
    }
    //bottom edge
    for (auto currentColumn{1}; currentColumn < (width - 1); currentColumn++) {//column 1 -> e-1
        maxHeight = (forest + (currentColumn + (width * (height - 1))))->z; //init on (e|c)
        for (auto currentRow = height - 2; currentRow > 0; currentRow--) { //row e-1 -> 1
            current = forest + (width * currentRow + currentColumn);
            if (maxHeight >= current->z) {
                current->bottomVisible = false;
            } else {
                maxHeight = current->z;
            }
        }
    }

    Tree *other;
    uint64_t visibleTrees{0};
    for (size_t counter{0}; counter < width * height; counter++) {
        other = (forest + counter);
        visibleTrees += other->isVisible();
    }
    free(forest);
    return visibleTrees;
}

uint64_t DayEight::partTwo() const {
    size_t width, height;
    auto forest = parse(&width, &height, false);
    uint32_t up, down, left, right, counter, maxScore{0};
    Tree *current, *other;
    for (auto currentRow{1}; currentRow < (height - 1); currentRow++) {//row 1 -> e-1
        for (auto currentColumn{1}; currentColumn < (width - 1); currentColumn++) {
            current = forest + (currentRow * width + currentColumn);
            //up
            counter = 1;
            for (auto u = currentRow - 1; u > 0; u--) {
                other = forest + (u * width + currentColumn);
                if (other->z >= current->z) {
                    break;
                }
                counter++;
            }
            up = counter;

            //down
            counter = 1;
            for (auto d = currentRow + 1; d < (height - 1); d++) {
                other = forest + (d * width + currentColumn);
                if (other->z >= current->z) {
                    break;
                }
                counter++;
            }
            down = counter;

            //left
            counter = 1;
            for (auto l = currentColumn - 1; l > 0; l--) {
                other = forest + (currentRow * width + l);
                if (other->z >= current->z) {
                    break;
                }
                counter++;
            }
            left = counter;

            //right
            counter = 1;
            for (auto r = currentColumn + 1; r < (width - 1); r++) {
                other = forest + (currentRow * width + r);
                if (other->z >= current->z) {
                    break;
                }
                counter++;
            }
            right = counter;

            maxScore = std::max(maxScore, up * down * left * right);
        }
    }
    free(forest);
    return maxScore;
}

Tree *DayEight::parse(size_t *w, size_t *h, const bool includeBools) const {
    auto height = lines.size();
    auto width = lines[0].size();
    *h = height;
    *w = width;

    Tree *forest = static_cast<Tree *>(calloc(height * width, sizeof(Tree)));
    uint8_t z;
    Tree *iterator = forest;
    if(includeBools) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                z = lines[y][x] - 48;
                iterator->z = z;
                iterator->topVisible = true;
                iterator->bottomVisible = true;
                iterator->leftVisible = true;
                iterator->rightVisible = true;
                iterator->isEdge = x == 0 || y == 0 || x == width - 1 || y == height - 1;
                iterator++;
            }
        }
    } else {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                z = lines[y][x] - 48;
                iterator->z = z;
                iterator->isEdge = x == 0 || y == 0 || x == width - 1 || y == height - 1;
                iterator++;
            }
        }
    }
    return forest;
}
