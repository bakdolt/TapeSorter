#include "FileHandler.h"
#include <iostream>

bool FileHandler::openFileForReading(std::ifstream& file, const std::string& filename) {
    file.open(filename, std::ios::binary);
    if (!file) {
        handleFileError("opening", filename);
        return false;
    }
    return true;
}

bool FileHandler::openFileForWriting(std::ofstream& file, const std::string& filename) {
    file.open(filename, std::ios::binary);
    if (!file) {
        handleFileError("creating", filename);
        return false;
    }
    return true;
}

void FileHandler::handleFileError(const std::string& operation, const std::string& filename) {
    std::cerr << "Error " << operation << " file: " << filename << std::endl;
} 