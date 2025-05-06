#include "OutputReader.h"
#include <iostream>

void OutputReader::readOutput(const std::string& filename) {
    std::ifstream file;
    if (!openFileForReading(file, filename)) {
        return;
    }

    int number;
    while (file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        printNumber(number);
    }
    std::cout << std::endl;
}

void OutputReader::readOutputToTxt(const std::string& bin_filename, const std::string& txt_filename) {
    std::ifstream bin_file;
    if (!openFileForReading(bin_file, bin_filename)) {
        return;
    }

    std::ofstream txt_file;
    if (!openFileForWriting(txt_file, txt_filename)) {
        return;
    }

    int number;
    while (bin_file.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        txt_file << number << " ";
    }
    txt_file << std::endl;

    std::cout << "File " << txt_filename << " has been created!" << std::endl;
}

void OutputReader::printNumber(int number) {
    std::cout << number << " ";
} 