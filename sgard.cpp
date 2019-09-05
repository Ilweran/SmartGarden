/*
 * sgard.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: eugene
 */


#include <iostream>
#include <string>
using namespace std;

#define CLS (cout << "\033[2J") //Clear screen
#define PROMPT (cout << "*************** Monitoring and Control Center ***************\n\n")
#define LOCATE(z,s) (cout << "\033[" << z << ';' << s << 'H')
#define INPUTERROR (cout << "Can't recognize input sequence. Please use \"help\" or \"?\""\a")

#include "humidity.h"



int main()
{
	CLS;
	LOCATE(1,1);
	cout << "\033[32m"; //Text color: green
	PROMPT;

	string command;
	enum commands {help = 1, draw_humidity_graph, show_current_temperature,
		show_temperature_magnitude, empty, cls, exit, unknown};
	commands cmd;
	const int samples = 13; //13 samples per hour
	int Humidity[] = {44, 43, 41, 39, 65, 75, 87, 99, 100, 97, 93, 90, 89};

	while(true)
	{
		cout << "> ";
		getline(cin, command);

		if(command == "?" || command == "help")
			cmd = help;
		else
			if(command == "show humidity")
				cmd = draw_humidity_graph;
			else
				if(command == "show current temperature")
					cmd = show_current_temperature;
				else
					if(command == "show temperature magnitude")
						cmd = show_temperature_magnitude;
					else
						if(command == "")
							cmd = empty;
						else
							if(command == "cls")
								cmd = cls;
							else
								if(command == "exit")
									cmd = exit;
								else cmd = unknown;

		switch(cmd)
		{
		case help:
			print_help();
			cout << endl;
			break;
		case draw_humidity_graph:
			humidity_graph(Humidity, samples);
			cout << endl;
			break;
		case show_current_temperature:
			cout << "25.3C" << endl;
			break;
		case show_temperature_magnitude:
			cout << "8.6C (12AM to 12PM)" << endl;
			break;
		case empty:
			cout << endl;
			break;
		case cls:
			CLS;
			LOCATE(1,1);
			PROMPT;
			break;
		case exit:
			return 0;
			break;
		case unknown:
			INPUTERROR;
			cout << endl;
			break;
		default:
			INPUTERROR;
			cout << endl;
			break;
		}

		command = "";
	}
}


