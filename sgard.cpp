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

