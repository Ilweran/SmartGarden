/*
 * consolemanager.cpp
 *
 *  Created on: 9 Jan 2020
 *      Author: Ilweran
 */

#include "consolemanager.h"
#include <iomanip>
#include <sstream>
using namespace std;

ConsoleManager::ConsoleManager()
{
  textColor = 32;
  language = "eng";
  commandHistoryLength = 20;
  prompt = '>';
  oak = new Trie("english");
  for(auto hC=historyCommands.begin(); hC!=historyCommands.end(); ++hC)
      *hC = "";
}

void ConsoleManager::clearScreen()
{
  cout << "\033[2J";
}

void ConsoleManager::locateCursor(int x, int y)
{
  cout << "\033[" << x << ';' << y << 'H';
}

void ConsoleManager::setTextColor(uint n)
{
  textColor = n;
  cout << "\033[" << n << "m";
}


void ConsoleManager::printPrompt()
{
  cout << prompt;
}

void ConsoleManager::printInputError()
{
  cout << "Can't recognize input sequence. Please use \"help\" or \"?\"\a";
}

void ConsoleManager::printHelp()
{
  cout.setf(std::ios::left, std::ios::adjustfield);
  cout.width(30);	cout << "\n? or help:";
  cout.width(50); cout << " output a list of available commands" << endl;
  cout.width(30); cout << "show humidity:";
  cout.width(50); cout << "draw a humidity graph" << endl;
  cout.width(30); cout << "show current temperature:";
  cout.width(50); cout << "print temperature data" << endl;
  cout.width(30); cout << "show temperature magnitude:";
  cout.width(50); cout << "print temperature magnitude" << endl;
  cout.width(30); cout << "cls:";
  cout.width(50); cout << "clear screen" << endl;
  cout.width(30); cout << "store word:";
  cout.width(50); cout << "insert a text string into a trie" << endl;
  cout.width(30); cout << "trie exists <name>";
  cout.width(50); cout << "check if trie <name> exists; possible values of name: \"english\"" << endl;
  cout.width(30); cout << "exit:";
  cout.width(50); cout << "exit application" << endl;
}

void ConsoleManager::input_and_store_Word()
{
  cout << "Input word: ";
  string word;
  getline(cin, word);
  oak->insertString(word);
}


bool ConsoleManager::trieExists(string trie_name)
{
    if(oak->getName() == trie_name)
      return true;
  return false;
}

void ConsoleManager::humidity_graph(int array[], const int arraySize)
{
  cout.unsetf(std::ios::adjustfield);
  int yMax = 26; //Number of lines in the graph
  for(int y = yMax-1; y >= 0; y--)
    {
      switch(y)
      {
	case 25:
	  cout << setw(6) << " ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] == 100)
	    {
	      cout << "1" << setw(5);
	    }
	    else cout << " " << setw(5);
	    cout << endl;
	  }
	  break;
	case 24:
	  cout << setw(6) << " ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] == 100)
	      cout << "0" << setw(5);
	    else if ((array[x] < 100) && (array[x] >= 90))
	      cout << "9" << setw(5);
	    else if ((array[x] < 90) && (array[x] >= 80))
	      cout << "8" << setw(5);
	    else if ((array[x] < 80) && (array[x] >= 70))
	      cout << "7" << setw(5);
	    else if ((array[x] < 70) && (array[x] >= 60))
	      cout << "6" << setw(5);
	    else if ((array[x] < 60) && (array[x] >= 50))
	      cout << "5" << setw(5);
	    else if ((array[x] < 50) && (array[x] >= 40))
	      cout << "4" << setw(5);
	    else if ((array[x] < 40) && (array[x] >= 30))
	      cout << "3" << setw(5);
	    else if ((array[x] < 30) && (array[x] >= 20))
	      cout << "2" << setw(5);
	    else if ((array[x] < 20) && (array[x] >= 10))
	      cout << "1" << setw(5);
	    else if ((array[x] < 10) && (array[x] >= 0))
	      cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 23:
	  cout << setw(6) << " ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] == 100)
	      cout << "0" << setw(5);
	    else cout << array[x] % 10 << setw(5);
	  }
	  cout << endl;
	  break;
	case 22:
	  cout << setw(0) << "H" << setw(1) << " " << "100 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] == 100)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 21:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 90)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 20:
	  cout << setw(0) << "u" << " " << " " << "90 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 90)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 19:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 80)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 18:
	  cout << setw(0) << "m" << " " << " " << "80 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 80)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 17:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 70)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 16:
	  cout << setw(0) << "i" << " " << " " << "70 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 70)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 15:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 60)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 14:
	  cout << setw(0) << "d" << " " << " " << "60 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 60)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 13:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 50)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 12:
	  cout << setw(0) << "i" << " " << " " << "50 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 50)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout<< endl;
	  break;
	case 11:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 40)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 10:
	  cout << setw(0) << "t" << " " << " " << "40 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 40)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 9:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 30)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 8:
	  cout << setw(0) << "y" << " " << " " << "30 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 30)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 7:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 20)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 6:
	  cout << setw(0) << " " << " " << " " << "20 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 20)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 5:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 10)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 4:
	  cout << setw(0) << "%" << " " << " " << "10 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] >= 10)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 3:
	  cout << setw(7);
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] > 0)
	      cout << "*" << setw(5);
	    else cout << " " << setw(5);
	  }
	  cout << endl;
	  break;
	case 2:
	  cout << setw(6) << "0 ";
	  for(int x = 0; x < arraySize; x++)
	  {
	    if(array[x] == 0)
	      cout << " " << setw(5);
	    else cout << "*" << setw(5);
	  }
	  cout << endl;
	  break;
	case 1:
	  cout << setw(7);
	  cout << endl;
	  break;
	case 0:
	  cout << setw(7) << "0";
	  for(int x = 1; x <= 12; x++)
	  {
	    cout << setw(5) << x*5;
	  }
	  cout << endl << endl;
	  break;
      }
    }
  cout << setw(50) << "Time (minutes)" << endl << endl;
}

bool ConsoleManager::execute_command(command cmd)
{
	switch(cmd)
	{
		case help:
		{
		  ConsoleManager::printHelp();
		  //cout << endl;
		  return true;
		}
	  	break;
		case draw_humidity_graph:
		{
		  ConsoleManager::humidity_graph(Humidity, samples);
		  //cout << endl;
		  return true;
		}
	  	break;
		case show_current_temperature:
		{
		  cout << "25.3C" << endl;
		  return true;
		}
		  break;
		case show_temperature_magnitude:
		  cout << "8.6C (12AM to 12PM)" << endl;
	  	  return true;
	  	break;
		case empty:
		  return true;
	  	break;
		case cls:
		{
		  ConsoleManager::clearScreen();
		  ConsoleManager::locateCursor(1,1);
		  ConsoleManager::printPrompt();
		  return true;
		}
	  	break;
		case word_store:
		{
		  ConsoleManager::input_and_store_Word();
		  //cout << endl;
		  return true;
		}
		break;
		case trie_exists:
		{
		  cout << "\n>Input trie name: ";
		  string trie_name = "";
		  getline(cin, trie_name);
		  if(ConsoleManager::trieExists(trie_name))
		    cout << "yes\n";
		  else
		    cout << "no\n";
		  return true;
		}
		break;
		case cli_exit:
		{
		  ConsoleManager::clearScreen();
		  ConsoleManager::locateCursor(1,1);
		  return false;
		}
	  	break;
		case unknown:
		{
		  ConsoleManager::printInputError();
		  //cout << endl;
		  return true;
		}
	  	break;
		default:
		{
		  ConsoleManager::printInputError();
		  //cout << endl;
		  return true;
		}
	  	break;
	}
}

command ConsoleManager::parse(string str)
{
  command cmd = unknown;
  if(str == "?" || str == "help")
    cmd = help;
  else
    if(str == "show humidity")
      cmd = draw_humidity_graph;
    else
      if(str == "show current temperature")
	cmd = show_current_temperature;
      else
	if(str == "show temperature magnitude")
	  cmd = show_temperature_magnitude;
	else
	  if(str == "")
	    cmd = empty;
	  else
	    if(str == "cls")
	      cmd = cls;
	    else
	      if(str == "trie exists")
		cmd = trie_exists;
	      else
		if(str == "exit")
		  cmd = cli_exit;
		else
		   if(str == "store word")
		     cmd = word_store;
		   else cmd = unknown;
  return cmd;
}
