#include "FileTape.h"
#include "TapeSorter.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    DelayConfig config("config.txt");
    FileTape input(argv[1], config);
    FileTape output(argv[2], config);

    size_t memory_limit = 1024;
    TapeSorter sorter(memory_limit);
    sorter.sort(input, output);

    std::cout << "Tape sorted\n";

    return 0;
}