#pragma once
#include <fstream>
#include <string>
#include <functional>

class FileHandler {
protected:
    static constexpr size_t BUFFER_SIZE = 1024;
    
    bool openFileForReading(std::ifstream& file, const std::string& filename);
    bool openFileForWriting(std::ofstream& file, const std::string& filename);
    void handleFileError(const std::string& operation, const std::string& filename);
}; 