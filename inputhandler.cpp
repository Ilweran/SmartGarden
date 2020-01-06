#include "inputhandler.h"
#include "humidity.h"
#include "auxlib.h"
#include <string>
#include <iostream>
using namespace std;

extern const int samples;
extern int Humidity[13];

command parse(string str)
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
								if(str == "exit")
									cmd = cli_exit;
								else
		if(str == "store word")
		  cmd = word_store;
		else cmd = unknown;
	return cmd;
}

bool execute_command(command cmd)
{

	switch(cmd)
	{
		case help:
	  	print_help();
	  	cout << endl;
			return true;
	  	break;
		case draw_humidity_graph:
			humidity_graph(Humidity, samples);
			cout << endl;
			return true;
	  	break;
		case show_current_temperature:
	  	cout << "25.3C" << endl;
			return true;
		  break;
		case show_temperature_magnitude:
	  	cout << "8.6C (12AM to 12PM)" << endl;
			return true;
	  	break;
		case empty:

			return true;
	  	break;
		case cls:
		  CLS;
	  	LOCATE(1,1);
	  	PROMPT;
			return true;
	  	break;
		case word_store:
		  input_and_store_Word();
		  cout << endl;
		  return true;
		break;
		case cli_exit:
		  CLS;
		  LOCATE(1,1);
	  	return false;
	  	break;
		case unknown:
		  INPUTERROR;
		  cout << endl;
			return true;
	  	break;
		default:
		  INPUTERROR;
		  cout << endl;
			return true;
	  	break;
	}
}
