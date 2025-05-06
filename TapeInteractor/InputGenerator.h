#pragma once
#include "FileHandler.h"
#include <random>
#include <sstream>

class InputGenerator : public FileHandler {
public:
    void generateRandom(const std::string& filename, int count, int min_val, int max_val);
    void generateFromConsole(const std::string& filename, const std::string& input);
    void generateFromTxt(const std::string& txt_filename, const std::string& bin_filename);
    
private:
    void writeNumberToFile(std::ofstream& file, int number);
}; 