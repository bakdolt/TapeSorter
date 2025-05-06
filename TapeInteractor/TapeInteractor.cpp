#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include <codecvt>
#include "TapeInteractor.h"
#include <limits>
#include <filesystem>

TapeInteractor::TapeInteractor() {
    std::filesystem::path exePath = std::filesystem::current_path();
    std::filesystem::path sharedDataPath = exePath / "SharedData";
    
    // Создаем директорию SharedData, если она не существует
    if (!std::filesystem::exists(sharedDataPath)) {
        std::filesystem::create_directory(sharedDataPath);
    }
    
    inputFilename = (sharedDataPath / "input.bin").string();
    outputFilename = (sharedDataPath / "output.bin").string();
}

void TapeInteractor::run() {
    while (true) {
        MenuManager::displayMainMenu();
        int choice = MenuManager::getUserChoice();
        
        switch (choice) {
            case 1:
                handleInputGeneration();
                break;
            case 2:
                handleOutputReading();
                break;
            case 3:
                return;
            default:
                MenuManager::displayError("Invalid choice. Please try again.");
        }
    }
}

void TapeInteractor::handleInputGeneration() {
    while (true) {
        MenuManager::displayInputMenu();
        int choice = MenuManager::getUserChoice();
        
        switch (choice) {
            case 1: {
                int count, min_val, max_val;
                std::cout << "Enter count of numbers: ";
                std::cin >> count;
                std::cout << "Enter minimum value: ";
                std::cin >> min_val;
                std::cout << "Enter maximum value: ";
                std::cin >> max_val;
                
                inputGenerator.generateRandom(inputFilename, count, min_val, max_val);
                break;
            }
            case 2: {
                std::cout << "Enter numbers (space-separated): ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string input;
                std::getline(std::cin, input);
                
                inputGenerator.generateFromConsole(inputFilename, input);
                break;
            }
            case 3: {
                // Используем путь относительно исполняемого файла
                std::filesystem::path exePath = std::filesystem::current_path();
                std::string txtFilename = (exePath / "SharedData" / "input.txt").string();
                
                inputGenerator.generateFromTxt(txtFilename, inputFilename);
                break;
            }
            case 4:
                return;
            default:
                MenuManager::displayError("Invalid choice. Please try again.");
        }
    }
}

void TapeInteractor::handleOutputReading() {
    while (true) {
        MenuManager::displayOutputMenu();
        int choice = MenuManager::getUserChoice();
        
        switch (choice) {
            case 1:
                outputReader.readOutput(outputFilename);
                break;
            case 2: {

                // Используем путь относительно исполняемого файла
                std::filesystem::path exePath = std::filesystem::current_path();
                std::string txtFilename = (exePath / "SharedData" / "output.txt").string();
                
                outputReader.readOutputToTxt(outputFilename, txtFilename);
                break;
            }
            case 3:
                return;
            default:
                MenuManager::displayError("Invalid choice. Please try again.");
        }
    }
}