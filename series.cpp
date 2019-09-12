/*	Created 11 Sep 2019
 *	Author: Ilweran
 *	*/



double calcNextValue(double x_cur)
{
	return x_cur*(2 - x_cur);
}

double getInitValue()
{
	double x0;
	cout << "Input initial value x0: ";
	cin >> x0;
	return x0;
}

void calcSeries(double x0)
{
	double x_cur = x0;
	x_next = calcNextValue(x_cur);
	double temp = 
}

