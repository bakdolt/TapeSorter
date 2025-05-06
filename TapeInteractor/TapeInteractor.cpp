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

// Значение по умолчанию для имён файлов
TapeInteractor::TapeInteractor() {
    inputFilename = "../SharedData/input.bin";
    outputFilename = "../SharedData/output.bin";
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
                // Значение по умолчанию для имени файла
                std::string txtFilename = "../SharedData/input.txt";
                
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
                // Значение по умолчанию для имени файла
                std::string txt_filename = "../SharedData/output.txt";
                
                outputReader.readOutputToTxt(outputFilename, txt_filename);
                break;
            }
            case 3:
                return;
            default:
                MenuManager::displayError("Invalid choice. Please try again.");
        }
    }
}