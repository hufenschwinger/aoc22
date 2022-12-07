#include <map>
#include <stack>
#include <list>
#include <set>
#include <algorithm>
#include <memory>
#include <utility>
#include "DaySeven.h"

using namespace aoc22;

Directory::Directory(std::shared_ptr<Directory> parent) {
    this->parent = std::move(parent);
    children = std::vector<std::shared_ptr<Directory>>();
    size = 0;
}

DaySeven::DaySeven() : IDay("../Days/inputs/7.txt") {

}

uint8_t DaySeven::number() const {
    return 7;
}

constexpr uint32_t maxSize = 100000;

static uint64_t sumOfDirsBelowLimit(const std::shared_ptr<Directory> &dir) {
    uint64_t sumOfEligibleDirs{0};
    for (const auto &child: dir->children) {
        sumOfEligibleDirs += sumOfDirsBelowLimit(child);
    }
    if (dir->size <= maxSize) {
        sumOfEligibleDirs += dir->size;
    }
    return sumOfEligibleDirs;
}

uint64_t DaySeven::partOne() const {
    std::shared_ptr<Directory> root = std::make_shared<Directory>(nullptr);
    std::shared_ptr<Directory> current = root;

    for (size_t i{1}; i < lines.size(); i++) { //skip first
        const std::string &line = lines[i];
        if (line.starts_with("$ cd ")) {
            if (line.substr(5, 2) == "..") { //updir
                current = current->parent;
            } else { //indir
                std::shared_ptr<Directory> child = std::make_shared<Directory>(current);
                current->children.push_back(child);
                current = child;
            }
        } else if (isdigit(line[0])) { //file
            size_t gap = line.find(' ');
            uint64_t size = std::stoull(line.substr(0, gap));
            std::shared_ptr<Directory> chain = current;
            do {
                chain->size += size;
                chain = chain->parent;
            } while (chain != nullptr);
        }
    }

    return sumOfDirsBelowLimit(root);
}

constexpr uint32_t diskSize = 70000000;
constexpr uintptr_t updateSize = 30000000;

static void appendAllSizes(const std::shared_ptr<Directory> &base, std::vector<uint64_t> &list) {
    list.push_back(base->size);
    for (const auto &child: base->children) {
        appendAllSizes(child, list);
    }
}

uint64_t DaySeven::partTwo() const {
    std::shared_ptr<Directory> root = std::make_shared<Directory>(nullptr);
    std::shared_ptr<Directory> current = root;

    for (size_t i{1}; i < lines.size(); i++) { //skip first
        const std::string &line = lines[i];
        if (line.starts_with("$ cd ")) {
            if (line.substr(5, 2) == "..") { //updir
                current = current->parent;
            } else { //indir
                std::shared_ptr<Directory> child = std::make_shared<Directory>(current);
                current->children.push_back(child);
                current = child;
            }
        } else if (isdigit(line[0])) { //file
            size_t gap = line.find(' ');
            uint64_t size = std::stoull(line.substr(0, gap));
            std::shared_ptr<Directory> chain = current;
            do {
                chain->size += size;
                chain = chain->parent;
            } while (chain != nullptr);
        }
    }

    uint64_t requiredSpace = updateSize - (diskSize - root->size);
    std::vector<uint64_t> sizes;
    appendAllSizes(root, sizes);
    std::sort(sizes.begin(), sizes.end());
    for (const auto &candidate: sizes) {
        if (candidate >= requiredSpace) {
            return candidate;
        }
    }
    return 0;
}