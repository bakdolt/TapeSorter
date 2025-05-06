#include "InputGenerator.h"
#include <iostream>

void InputGenerator::generateRandom(const std::string& filename, int count, int min_val, int max_val) {
    std::ofstream file;
    if (!openFileForWriting(file, filename)) {
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min_val, max_val);

    for (int i = 0; i < count; ++i) {
        writeNumberToFile(file, dist(gen));
    }

    std::cout << "File " << filename << " has been created!" << std::endl;
}

void InputGenerator::generateFromConsole(const std::string& filename, const std::string& input) {
    std::ofstream file;
    if (!openFileForWriting(file, filename)) {
        return;
    }

    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        writeNumberToFile(file, num);
    }

    std::cout << "File " << filename << " has been created!" << std::endl;
}

void InputGenerator::generateFromTxt(const std::string& txt_filename, const std::string& bin_filename) {
    std::ifstream txt_file;
    if (!openFileForReading(txt_file, txt_filename)) {
        return;
    }

    std::ofstream bin_file;
    if (!openFileForWriting(bin_file, bin_filename)) {
        return;
    }

    int num;
    while (txt_file >> num) {
        writeNumberToFile(bin_file, num);
    }

    std::cout << "File " << bin_filename << " has been created!" << std::endl;
}

void InputGenerator::writeNumberToFile(std::ofstream& file, int number) {
    file.write(reinterpret_cast<const char*>(&number), sizeof(int));
} 