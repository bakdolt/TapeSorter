#pragma once
#include "../TapeSorter/Tape.h"
#include <vector>
#include <stdexcept>

class MockTape : public Tape {
public:
    MockTape();

    MockTape(const std::vector<int>& data);

    int read() override;

    void write(int value) override;

    void moveForward() override;

    void moveBackward() override;

    void rewindToStart() override;

    bool isAtEnd() const override;

    size_t getSize() const override;

    size_t getCurrentPosition() const override;

    const std::vector<int>& getData() const;

    void setData(const std::vector<int>& data);

private:
    std::vector<int> data;
    size_t position;
}; 