/*
#################################################################
||                                                             ||
||Planets.h - Main module for simulating planetary type objects||
||                       Copyright: 2021                       ||
||                        License: MIT                         ||
||              Authors: Radu Herzal, Cocea Vlad               ||
||                                                             ||
#################################################################
*/


#ifndef PLANETS_H_INCLUDED
#define PLANETS_H_INCLUDED
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "Helpful.h"


struct Star
{
    double mass;
    double positionX;
    double positionY;
};

struct Planet
{
    double mass;
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double accelerationX;
    double accelerationY;
};

extern void init_Planet(struct Planet *p, double mass, double positionX, double positionY, double velocityX, double velocityY);
extern void init_Star(struct Star *s, double mass, double positionX, double positionY);

extern void update_System(int nPlanet, struct Planet *p, int nStar, struct Star *s, double gconst, double dt);

extern void print_System(int nPlanet, struct Planet *p, int nStar, struct Star *s, FILE *f, double t);


#endif // PLANETS_H_INCLUDED
