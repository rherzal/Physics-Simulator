/*
####################################################
||                                                ||
||Plotter.c - See Plotter.h for copyright and info||
||                                                ||
||                                                ||
####################################################
*/

#include "Plotter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//initializes a Plotter object.
//Points the handler to the file settings.plot which will generate the instructions for gnuplot
//copies the name of the data file into data
void init_Plotter(struct Plotter *p, char *data)
{
    p->handler = fopen(".\\gnuplot\\bin\\settings.plt", "w+");
    strcpy(p->data, data);
}


//invokes gnuplot
//in command it stores the instructions that will be saved in the handler
//in buffer it converts the column integer into a string
//saves the instructions into handler and then calls gnuplot to execute the instruction file using system commands
void plot_Plotter(struct Plotter *p, int x_Data, int y_Data)
{
    char command[255];
    strcpy(command, "set datafile separator \",\" \nplot '");
    strcat(command, p->data);
    strcat(command, "' using ");
    char buff[10];
    sprintf(buff, "%d", x_Data);
    strcat(command, buff);
    strcat(command, ":");
    sprintf(buff, "%d", y_Data);
    strcat(command, buff);
    fprintf(p->handler, command);
    fclose(p->handler);
    system(".\\gnuplot\\bin\\gnuplot -p .\\gnuplot\\bin\\settings.plt");
}


