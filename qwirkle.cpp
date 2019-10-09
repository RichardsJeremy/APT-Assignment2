
#include "LinkedList.h"

#include <iostream>
#include "menu.cpp"
#include "controller.cpp"

#define EXIT_SUCCESS 0

int main(void)
{

   menu *menuTest = new menu();
   menuTest->runMenu();

   return EXIT_SUCCESS;
}
