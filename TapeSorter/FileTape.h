#pragma once
#include "Tape.h"
#include "DelayConfig.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <chrono>
#include <thread>


class FileTape : public Tape {
public:
    FileTape(const std::string& filename, const DelayConfig& config);
    ~FileTape();

    int read() override;
    void write(int value) override;
    void moveForward() override;
    void moveBackward() override;
    void rewindToStart() override;
    size_t getSize() const override;
    size_t getCurrentPosition() const override;
    bool isAtEnd() const override;

private:
    void applyDelay(size_t delay_ms) const;
    void updateFileSize();

    std::fstream file;
    std::string filename;
    size_t currentPos = 0;
    size_t size = 0;
    DelayConfig delays;
};