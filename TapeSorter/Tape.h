#pragma once

#include <cstddef>

class Tape {
public:
    virtual ~Tape() = default;
    virtual int read() = 0;
    virtual void write(int value) = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void rewindToStart() = 0;
    virtual size_t getSize() const = 0;
    virtual size_t getCurrentPosition() const = 0;
    virtual bool isAtEnd() const = 0;
};