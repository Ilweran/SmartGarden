/*
 * sgard.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: Ilweran
 */


#include <iostream>
#include <string>
using namespace std;

#include "consolemanager.h"

int main()
{
  ConsoleManager console;
  console.clearScreen();
  console.setTextColor(32);	//Text color: green
  console.locateCursor(1,1);

  do
  {
    console.printPrompt();
    getline(cin, console.input_str);
  } while(console.execute_command(console.parse(console.input_str)));

  return 0;
}

