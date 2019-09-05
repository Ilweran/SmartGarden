/*
 * humidity.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: Ilweran
 */

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include <iomanip>
using std::setw;

void print_help()
{
	cout << "\n? or help:									output a list of available commands" << endl;
	cout << "show humidity:								draw a humidity graph" << endl;
	cout << "show current temperature:		print temperature data" << endl;
	cout << "show temperature magnitude:	print temperature magnitude" << endl;
	cout << "cls:													clear screen" << endl;
	cout << "exit:												exit application" << endl;
}

void humidity_graph(int array[], const int arraySize)
{
	int yMax = 26;
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
						cout << "1";
						setw(5);
					}
					else cout << " " << setw(5);
				}
				cout << endl;
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
	cout << setw(40) << "Time (minutes)" << endl << endl;
}
