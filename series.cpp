/*	Created 11 Sep 2019
 *	Author: Ilweran
 *	*/

#include <cstring>
#include <chrono>
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

#include "series.h"
#include "inputhandler.h"

double calcNextValue(double x_cur)
{
	return x_cur*(2 - x_cur);
}

double getInitValue()
{
	double x0;
	cout << "Input initial value x0: "; //Add check for correctness of input!
	cin >> x0;
	return x0;
}

void processCurrentValue(double x)
{
  

}

void calcSeries(double x0, double calcNextValue(double))
{
  double x_cur = x0;
  double x_next = 0;
  chrono::time_point<std::chrono::system_clock> start, end;
  auto start = chrono::steady_clock::now();
  int elapsed_seconds = 0;
    
  do
  {
    x_next = calcNextValue(x_cur);
    processCurrentValue(x_cur);
    auto end = std::chrono::system_clock::now();
    elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds> (end-start).count();
  } while((abs(x_next - x_cur) > epsilon) || elapsed_seconds < 30)

  printMessage("Divergent sequence? Press any key to stop calculation.");
  
  while(!kbhit())
  {
    x_next = calcNextValue(x_cur);
    processCurrentValue(x_cur);
  }
}

void  printMessage(string str)
{
  LOCATE(40,1)
  cout << str;
}

