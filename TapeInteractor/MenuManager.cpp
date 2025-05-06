#include "MenuManager.h"
#include <iostream>

int MenuManager::getUserChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

void MenuManager::displayMainMenu() {
    std::cout << "\n=== Tape Operations Menu ===" << std::endl;
    std::cout << "1. Generate input file" << std::endl;
    std::cout << "2. Read output file" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void MenuManager::displayInputMenu() {
    std::cout << "\n=== Input Generation Menu ===" << std::endl;
    std::cout << "1. Generate random numbers" << std::endl;
    std::cout << "2. Enter numbers from console" << std::endl;
    std::cout << "3. Convert from text file" << std::endl;
    std::cout << "4. Back to main menu" << std::endl;
    std::cout << "Enter your choice: ";
}

void MenuManager::displayOutputMenu() {
    std::cout << "\n=== Output Reading Menu ===" << std::endl;
    std::cout << "1. Display numbers in console" << std::endl;
    std::cout << "2. Save to text file" << std::endl;
    std::cout << "3. Back to main menu" << std::endl;
    std::cout << "Enter your choice: ";
}

void MenuManager::displayError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}

void MenuManager::displaySuccess(const std::string& message) {
    std::cout << "Success: " << message << std::endl;
} 