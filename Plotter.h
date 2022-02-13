/*
#############################################
||                                         ||
||Plotter.h - Main module for plotting data||
||             Copyright: 2021             ||
||              License:  MIT              ||
||    Authors: Radu Herzal, Cocea Vlad     ||
||                                         ||
||                                         ||
#############################################
*/




#ifndef PLOTTER_H_INCLUDED
#define PLOTTER_H_INCLUDED

#include <windows.h>
#include <stdio.h>

//definition of a Plotter structure
struct Plotter
{
    FILE *handler;
    char data[255];
};

//initializes the Plotter and points it to the data it can plot
//it also initializes the handler (The path to the settings file)
extern void init_Plotter(struct Plotter *p, char *data);


//tells plotter to plot the column y_Data in terms of x_Data from the data file
extern void plot_Plotter(struct Plotter *p, int x_Data, int y_Data);


#endif // PLOTTER_H_INCLUDED
