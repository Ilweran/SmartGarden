/*
 * sgard.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: Ilweran
 */


#include <iostream>
#include <string>
using namespace std;

#include "humidity.h"
#include "inputhandler.h"

int main()
{
//	enum command {help = 1, draw_humidity_graph, show_current_temperature,
//		    show_temperature_magnitude, empty, cls, cli_exit, unknown};
	
	CLS;
	LOCATE(1,1);
	cout << "\033[32m"; //Text color: green
	PROMPT;

	string input_str = "";

	do
	{
		cout << "> ";
		getline(cin, input_str);
	} while(execute_command(parse(input_str)));

	return 0;
}

