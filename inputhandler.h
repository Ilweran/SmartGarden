#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <string>
using namespace std;

#include "humidity.h"

#define CLS (cout << "\033[2J") //Clear screen
#define PROMPT (cout << "*************** Monitoring and Control Center ***************\n\n")
#define LOCATE(z,s) (cout << "\033[" << z << ';' << s << 'H')
#define INPUTERROR (cout << "Can't recognize input sequence. Please use \"help\" or \"?\"\a")


enum command {help = 1, draw_humidity_graph, show_current_temperature,
	    show_temperature_magnitude, empty, cls, cli_exit, word_store, unknown};

command parse(string str);

bool execute_command(command cmd);

#endif //INPUTHANDLER_H_
