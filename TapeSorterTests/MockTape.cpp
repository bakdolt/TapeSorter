#include "MockTape.h"

MockTape::MockTape(): position(0) {}

MockTape::MockTape(const std::vector<int>& data = {}) : data(data), position(0) {}

int MockTape::read() {
    if (position >= data.size()) {
        throw std::runtime_error("position >= data.size()");
    }
    return data[position];
}

void MockTape::write(int value) {
    if (position >= data.size()) {
        data.push_back(value);
    }
    else {
        data[position] = value;
    }
}

void MockTape::moveForward() {
    if (position >= data.size()) {
        throw std::runtime_error("position >= data.size()");
    }
    position++;
}

void MockTape::moveBackward() {
    if (position == 0) {
        throw std::runtime_error("possition cannot be < 0");
    }
    position--;
}

void MockTape::rewindToStart() {
    position = 0;
}

bool MockTape::isAtEnd() const {
    return position >= data.size();
}

size_t MockTape::getSize() const {
    return data.size();
}

size_t MockTape::getCurrentPosition() const {
    return position;
}

const std::vector<int>& MockTape::getData() const {
    return data;
}

void MockTape::setData(const std::vector<int>& data) {
    this->data = data;
    position = 0;
}
