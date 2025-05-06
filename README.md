# TapeSorter

Проект для сортировки данных на ленте (tape) с учетом ограничения оперативной памяти и задержек операций чтения/записи

## Описание проекта

Проект состоит из трех основных компонентов:
- `TapeSorter` - основная библиотека для сортировки данных
- `TapeInteractor` - библиотека для взаимодействия с пользователем
- `TapeSorterTests` - модульные тесты

### Основные классы

#### Tape (Интерфейс)
```cpp
class Tape {
    virtual int read() = 0;
    virtual void write(int value) = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void rewindToStart() = 0;
    virtual bool isAtEnd() const = 0;
    virtual size_t getSize() const = 0;
    virtual size_t getCurrentPosition() const = 0;
};
```
Базовый класс для работы с лентой. Определяет основные операции:
- `read()` - чтение значения
- `write()` - запись значения
- `moveForward()` - перемещение вперед
- `moveBackward()` - перемещение назад
- `rewindToStart()` - возврат в начало
- `isAtEnd()` - проверка конца ленты
- `getSize()` - получение размера
- `getCurrentPosition()` - получение текущей позиции

#### FileTape
Реализация Tape для работы с файлами. Учитывает задержки операций через DelayConfig.

#### TapeSorter
Основной класс для сортировки данных на ленте. Использует алгоритм сортировки слиянием с учетом ограничений памяти.

#### DelayConfig
- Файл конфигурации задержек (`config.txt`)
Конфигурация задержек для операций с лентой:
- `readDelay` - задержка для чтения
- `writeDelay` - задержка для записи
- `moveDelay` - задержка для перемещения
- `rewindDelayPerPosition` - при перемотке в самое начало, задержка перемотки на 1 позицию (предполагается, что она меньше чем при единичном сдвиге)

#### TapeInteractor
Библиотека для взаимодействия с пользователем. Работает с директорией `SharedData`, где хранятся:
- Входные файлы для сортировки
- Выходные файлы с отсортированными данными

## Сборка проекта

### Требования
- CMake 3.15 или выше
- Компилятор с поддержкой C++20
- Google Test (для тестов)

### Инструкция по сборке

1. Клонируйте репозиторий:
```bash
git clone https://github.com/bakdolt/TapeSorter
cd TapeSorter
```

2. Создайте и перейдите в директорию сборки:
```bash
mkdir build
cd build
```

3. Сконфигурируйте проект:
```bash
cmake .. -DBUILD_TESTING=ON
```

4. Соберите проект:
```bash
# Для Debug версии
cmake --build . --config Debug

# Для Release версии
cmake --build . --config Release
```

5. Запуск тестов:
```bash
ctest -C Debug --output-on-failure
```

### Структура CMake

Проект использует CMake для сборки. Основные файлы:
- `CMakeLists.txt` - корневой файл конфигурации
- `TapeSorter/CMakeLists.txt` - конфигурация основной библиотеки
- `TapeInteractor/CMakeLists.txt` - конфигурация библиотеки взаимодействия
- `TapeSorterTests/CMakeLists.txt` - конфигурация тестов

После сборки в директории `build/bin/[Debug|Release]` будут находиться:
- `TapeSorterApp.exe` - приложение для сортировки
- `TapeInteractorApp.exe` - приложение для взаимодействия с пользователем
- `SharedData/` - директория для входных/выходных файлов

### Конфигурация задержек

Создайте файл конфигурации `config.txt` со следющими параметрами:
```
readDelay writeDelay moveDelay rewindDelayPerPosition
```

Пример:
```
10 20 5 2
```

### Запуск TapeInteractorApp

1. Запустите `TapeInteractorApp.exe`
2. Используйте меню для:
   - Генерации входных данных
   - Просмотра результатов сортировки
   - Выхода из программы
Файлы складываются в директорию SharedData

### Запуск TapeSorterApp

```bash
./TapeSorterApp <input> <output>
```

Пример:

```bash
./TapeSorterApp SharedData/input.bin SharedData/output.bin
```

## Тестирование

Проект включает модульные тесты, использующие Google Test Framework. Тесты проверяют:
- Сортировку пустого массива
- Сортировку одного элемента
- Сортировку уже отсортированного массива
- Сортировку массива в обратном порядке
- Сортировку случайного массива
- Сортировку массива с дубликатами
- Сортировку с разными размерами памяти
- Сортировку большого массива
- Сортировку массива с отрицательными числами