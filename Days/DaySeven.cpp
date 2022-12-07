#include <map>
#include <stack>
#include <list>
#include <set>
#include <algorithm>
#include "DaySeven.h"

using namespace aoc22;

DaySeven::DaySeven() : IDay("../Days/inputs/7.txt") {

}

uint8_t DaySeven::number() const {
    return 7;
}

constexpr uint32_t maxSize = 100000;

uint64_t DaySeven::partOne() const {
    std::unordered_map<std::string, uint64_t> fileSystem; //fully-qualified filepaths w/ sizes
    std::list<std::string> location; //track current location
    //parse input
    for (size_t i{1}; i < lines.size(); i++) { //skip first
        const std::string &line = lines[i];
        if (line.starts_with("$ cd ")) {
            if (line.substr(5, 2) == "..") { //updir
                location.pop_back();
            } else { //indir
                location.push_back(line.substr(5));
            }
        } else if (isdigit(line[0])) { //file
            size_t gap = line.find(' ');
            uint64_t size = std::stoull(line.substr(0, gap));
            std::string name = line.substr(gap + 1);
            std::string fullPath{"/"};
            for (const auto &dir: location) { //build full path
                fullPath += dir + "/";
            }
            fullPath += name;
            fileSystem.emplace(fullPath, size);
        }
    }

    //determine dirs
    std::set<std::string> directories;
    for (const auto &entry: fileSystem) {
        std::string fullName = entry.first;
        size_t lastSep = fullName.find_last_of('/');
        std::string parent = entry.first.substr(0, lastSep);
        directories.emplace(parent);
        while (parent.find('/') != std::string::npos) {
            lastSep = parent.find_last_of('/');
            parent = parent.substr(0, lastSep);
            directories.emplace(parent);
        }
    }

    uint64_t sum{0};
    {//measure root dir
        uint64_t rootSum{0};
        for (const auto &file: fileSystem) {
            rootSum += file.second;
        }
        if (rootSum <= maxSize) {
            sum += rootSum;
        }
    }

    for (const auto &dir: directories) { //check dir sizes
        uint64_t dirSum{0};
        for (const auto &file: fileSystem) {
            if (file.first.starts_with(dir)) {
                dirSum += file.second;
            }
        }
        if (dirSum <= maxSize) {
            sum += dirSum;
        }
    }
    return sum;
}

constexpr uint32_t diskSize = 70000000;
constexpr uintptr_t updateSize = 30000000;

uint64_t DaySeven::partTwo() const {
    std::unordered_map<std::string, uint64_t> fileSystem; //fully-qualified filepaths w/ sizes
    std::list<std::string> location; //track current location
    //parse input
    for (size_t i{1}; i < lines.size(); i++) { //skip first
        const std::string &line = lines[i];
        if (line.starts_with("$ cd ")) {
            if (line.substr(5, 2) == "..") { //updir
                location.pop_back();
            } else { //indir
                location.push_back(line.substr(5));
            }
        } else if (isdigit(line[0])) { //file
            size_t gap = line.find(' ');
            uint64_t size = std::stoull(line.substr(0, gap));
            std::string name = line.substr(gap + 1);
            std::string fullPath{"/"};
            for (const auto &dir: location) { //build full path
                fullPath += dir + "/";
            }
            fullPath += name;
            fileSystem.emplace(fullPath, size);
        }
    }

    //determine dirs
    std::set<std::string> directories;
    for (const auto &entry: fileSystem) {
        std::string fullName = entry.first;
        size_t lastSep = fullName.find_last_of('/');
        std::string parent = entry.first.substr(0, lastSep);
        directories.emplace(parent);
        while (parent.find('/') != std::string::npos) {
            lastSep = parent.find_last_of('/');
            parent = parent.substr(0, lastSep);
            directories.emplace(parent);
        }
    }
    std::vector<uint64_t> sizes;

    uint64_t sum{0};
    uint64_t rootSum{0};
    {//measure root dir
        for (const auto &file: fileSystem) {
            rootSum += file.second;
        }
        sizes.push_back(rootSum);
    }

    for (const auto &dir: directories) { //check dir sizes
        uint64_t dirSum{0};
        for (const auto &file: fileSystem) {
            if (file.first.starts_with(dir)) {
                dirSum += file.second;
            }
        }
        sizes.push_back(dirSum);
    }
    uint64_t requiredSpace = updateSize - (diskSize - rootSum);
    std::sort(sizes.begin(), sizes.end());
    for(const auto& candidate : sizes) {
        if (candidate >= requiredSpace) {
            return candidate;
        }
    }
    return 0;
}