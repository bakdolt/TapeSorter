#pragma once
#include "InputGenerator.h"
#include "OutputReader.h"
#include "MenuManager.h"
#include <string>

class TapeInteractor {
public:
    TapeInteractor();
    void run();

private:
    void handleInputGeneration();
    void handleOutputReading();
    
    InputGenerator inputGenerator;
    OutputReader outputReader;
    std::string inputFilename;
    std::string outputFilename;
}; 