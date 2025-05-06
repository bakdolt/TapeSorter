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
    // �������� ��� ������
    size_t readDelay = 0;
    // �������� ��� ������
    size_t writeDelay = 0;
    // �������� ��� ������ �� 1 �������
    size_t moveDelay = 0;
    // ��� ��������� � ����� ������, �������� ��������� �� 1 ������� (��������������, ��� ��� ������ ��� ��� ��������� ������)
    size_t rewindDelayPerPosition = 0;
};