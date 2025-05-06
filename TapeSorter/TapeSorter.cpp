#include "TapeSorter.h"
#include "FileTape.h"
#include <algorithm>
#include <queue>
#include <fstream>
#include <filesystem>

struct HeapElement {
    int value;
    size_t tape_idx;
    bool operator>(const HeapElement& other) const { return value > other.value; }
};

TapeSorter::TapeSorter(size_t memory_limit) : memory_limit(memory_limit) {}

void TapeSorter::sort(Tape& input, Tape& output) {
    auto chunk_files = splitIntoChunks(input);
    mergeChunks(chunk_files, output);
    cleanTempFiles(chunk_files);
}

std::vector<std::string> TapeSorter::splitIntoChunks(Tape& input) {
    // Размер одной временной ленты определяется лимитом оперативной памяти
    std::vector<std::string> chunk_files;
    size_t chunk_size = memory_limit / sizeof(int);
    std::vector<int> buffer;

    input.rewindToStart();
    while (!input.isAtEnd()) {
        buffer.clear();
        for (size_t i = 0; i < chunk_size && !input.isAtEnd(); ++i) {
            buffer.push_back(input.read());
            input.moveForward();
        }
        std::sort(buffer.begin(), buffer.end());

        std::filesystem::path exePath = std::filesystem::current_path();
        std::filesystem::path tmpPath = exePath / "tmp";

        if (!std::filesystem::exists(tmpPath)) {
            std::filesystem::create_directory(tmpPath);
        }

        // Создаем временные ленты tmp/chunk_{номер}
        std::string chunk_name = "tmp/chunk_" + std::to_string(chunk_files.size());
        DelayConfig config; // нулевые задержки для временных лент
        FileTape chunk_tape(chunk_name, config);
        for (int num : buffer) {
            chunk_tape.write(num);
            chunk_tape.moveForward();
        }
        chunk_files.push_back(chunk_name);
    }
    return chunk_files;
}

void TapeSorter::mergeChunks(const std::vector<std::string>& chunk_files, Tape& output) {
    std::vector<std::unique_ptr<Tape>> tapes;
    std::priority_queue<HeapElement, std::vector<HeapElement>, std::greater<>> heap;

    // Открываем все временные ленты
    DelayConfig config; // нулевые задержки для временных лент
    for (const auto& file : chunk_files) {
        tapes.emplace_back(std::make_unique<FileTape>(file, config));
        tapes.back()->rewindToStart();
        if (!tapes.back()->isAtEnd()) {
            heap.push({ tapes.back()->read(), tapes.size() - 1 });
        }
    }
    // Слияние
    output.rewindToStart();
    HeapElement min;
    while (!heap.empty()) {
        min = heap.top();
        heap.pop();
        output.write(min.value);
        output.moveForward();

        auto& tape = *tapes[min.tape_idx];
        tape.moveForward();
        if (!tape.isAtEnd()) {
            heap.push({ tape.read(), min.tape_idx });
        }
    }
    /*
    При слиянии НЕ загружаются все временные ленты сразу в оперативную память
    - от каждой загружается по одному первому элементу, по которому их сортирует куча
    Сразу же как элемент достается из кучи - запиывается в выходную ленту, потом перезаписывается следующим
    */
}

// Удаление всех времнных лент, очистка памяти
void TapeSorter::cleanTempFiles(const std::vector<std::string>& files) {
    for (const auto& file : files) {
        std::filesystem::remove(file);
    }
}