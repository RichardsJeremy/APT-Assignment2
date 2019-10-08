#include "menu.h"
#include "controller.h"

void menu::printMenu()
{
    std::cout << "Menu"
              << "\n"
              << "----" 
              << "\n"
              << "1. New Game\n"
              << "2. Load Game\n"
              << "3. Show Student Information\n"
              << "4. Quit\n";
}

void menu::runMenu()
{
    std::shared_ptr<controller> ctrl = std::make_shared<controller>();
    int choice = 0;
    do
    {
        printMenu();
        std::cout << "\n";
        std::cin >> choice;
        ctrl->choose(choice);
    }
    while (choice != 4);
    
}