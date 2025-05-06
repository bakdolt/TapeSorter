#include "FileTape.h"
#include <fstream>

FileTape::FileTape(const std::string& filename, const DelayConfig& config)
    : filename(filename), delays(config) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!file) {
        file.open(filename, std::ios::out | std::ios::binary);
        file.close();
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    }
    updateFileSize();
}

FileTape::~FileTape() {
    file.close();
}

void FileTape::applyDelay(size_t delay_ms) const {
    if (delay_ms > 0) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

void FileTape::updateFileSize() {
    file.seekg(0, std::ios::end);
    size = file.tellg() / sizeof(int);
    file.seekg(currentPos * sizeof(int));
}

int FileTape::read() {
    applyDelay(delays.getReadDelay());
    int value;
    file.seekg(currentPos * sizeof(int));
    file.read(reinterpret_cast<char*>(&value), sizeof(int));
    return value;
}

void FileTape::write(int value) {
    applyDelay(delays.getWriteDelay());
    file.seekp(currentPos * sizeof(int));
    file.write(reinterpret_cast<const char*>(&value), sizeof(int));
    file.flush();
    updateFileSize();
}

void FileTape::moveForward() {
    if (currentPos < size) {
        applyDelay(delays.getMoveDelay());
        currentPos++;
    }
}

void FileTape::moveBackward() {
    if (currentPos > 0) {
        applyDelay(delays.getMoveDelay());
        currentPos--;
    }
}

void FileTape::rewindToStart() {
    size_t rewind_steps = currentPos;
    applyDelay(static_cast<size_t>(rewind_steps * delays.getRewindDelayPerPosition()));
    currentPos = 0;
}

size_t FileTape::getSize() const {
    return size;
}

size_t FileTape::getCurrentPosition() const {
    return currentPos;
}

bool FileTape::isAtEnd() const {
    return currentPos >= size;
}