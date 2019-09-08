/*
 * humidity.h
 *
 *  Created on: Sep 16, 2018
 *      Author: Ilweran
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_


extern const int samples; //13 samples per hour
extern int Humidity[13];

void humidity_graph(int array[], const int arraySize);
void print_help();


#endif /* HUMIDITY_H_ */
