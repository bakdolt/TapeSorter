#pragma once
#include <string>
#include <fstream>
#include <iostream>

// ������������ �������� ����� (� ��)
class DelayConfig {
public:
    DelayConfig();
    DelayConfig(const std::string filename);
    size_t getReadDelay() const;
    size_t getWriteDelay() const;
    size_t getMoveDelay() const;
    size_t getRewindDelayPerPosition() const;
private:
    // Задержка для чтения
    size_t readDelay = 0;
    // Задержка для записи
    size_t writeDelay = 0;
    // Задержка для сдвига на 1 позицию
    size_t moveDelay = 0;
    // При перемотке в самое начало, задержка перемотки на 1 позицию (предполагается, что она меньше чем при единичном сдвиге)
    size_t rewindDelayPerPosition = 0;
};