/*
 * consolemanager.h
 *
 *  Created on: 8 Jan 2020
 *      Author: Ilweran
 */

#ifndef CONSOLEMANAGER_H_
#define CONSOLEMANAGER_H_

#include "trie.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum command {help = 1, draw_humidity_graph, show_current_temperature,
  	    show_temperature_magnitude, empty, cls, cli_exit, word_store, trie_exists, enable,
	    disable, unknown};


class ConsoleManager
{
  public:
  ConsoleManager();
 ~ConsoleManager() {};

   void clearScreen(); 				//Replaces CLS macro
   void locateCursor(int, int);			//Replaces LOCATE macro
   void setTextColor(uint);
   void setTextDecor(uint);
   void printPrompt();
   void input_and_store_Word();
   bool trieExists(string);
   bool executeCommand();
   void printInputError();
   command parse(string str);
   bool execute_command(command cmd);
   void printHelp();
   void humidity_graph(int array[], const int arraySize);
   string input_str = "";
   void setPrompt(string);

  private:
  unsigned short int textColor;
  string language;
  unsigned short int commandHistoryLength;
  vector<string> historyCommands;
  Trie* oak;
  string prompt;
  int Humidity[13] = {44, 43, 41, 39, 65, 75, 87, 99, 100, 97, 93, 90, 89};
  const int samples = 13; //13 samples per hour
};



#endif /* CONSOLEMANAGER_H_ */
