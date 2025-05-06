#pragma once

#include "Tape.h"
#include <vector>
#include <string>

class TapeSorter {
public:
    TapeSorter(size_t memory_limit);
    void sort(Tape& input, Tape& output);

private:
    size_t memory_limit;
    std::vector<std::string> splitIntoChunks(Tape& input);
    void mergeChunks(const std::vector<std::string>& chunk_files, Tape& output);
    void cleanTempFiles(const std::vector<std::string>& files);
};