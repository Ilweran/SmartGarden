/* Created 11 Sep 2019 by Ilweran */

#include <iostream>
#include <cstring>
using namespace std;

double epsilon = 0.01;

double calcNextValue(double);

double getInitValue();

void calcSeries(double, double (*f)(double));

void printMessage(string);

void processCurrentValue(double);
