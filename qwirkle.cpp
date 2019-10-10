
#include "LinkedList.h"

#include <iostream>
#include "menu.h"
#include "controller.h"

#define EXIT_SUCCESS 0

int main(void)
{

   menu *menuTest = new menu();
   menuTest->runMenu();

   return EXIT_SUCCESS;
}
