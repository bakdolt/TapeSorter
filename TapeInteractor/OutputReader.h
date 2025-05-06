#pragma once
#include "FileHandler.h"
#include <vector>

class OutputReader : public FileHandler {
public:
    void readOutput(const std::string& filename);
    void readOutputToTxt(const std::string& bin_filename, const std::string& txt_filename);
    
private:
    void printNumber(int number);
}; 