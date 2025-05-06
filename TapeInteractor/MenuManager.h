#pragma once
#include <string>

class MenuManager {
public:
    static int getUserChoice();
    static void displayMainMenu();
    static void displayInputMenu();
    static void displayOutputMenu();
    static void displayError(const std::string& message);
    static void displaySuccess(const std::string& message);
}; 