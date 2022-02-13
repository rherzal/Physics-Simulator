/*
#################################################################
||                                                             ||
||Pendulum.h - Main module for simulating pendulum type objects||
||                       Copyright: 2021                       ||
||                        License: MIT                         ||
||              Authors: Radu Herzal, Cocea Vlad               ||
||                                                             ||
#################################################################
*/


#ifndef PENDULUM_H_INCLUDED
#define PENDULUM_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include "Helpful.h"
//ALL THETA's ARE MEASURED IN TERMS OF -PI/2

struct SimplePendulum
{
    double mass;
    double lenght;
    double gconst;
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double theta;
    double omega;
    double alpha;
};

extern void init_SimplePendulum(struct SimplePendulum *p, double theta, double lenght, double gconst, double mass);
extern void update_SimplePendulum(struct SimplePendulum *p, double dt);
extern void print_SimplePendulum(struct SimplePendulum *p, FILE *f, double t);



struct DampenedPendulum
{
    double mass;
    double lenght;
    double gconst;
    double fconst;
    double theta;
    double omega;
    double alpha;
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
};

extern void init_DampenedPendulum(struct DampenedPendulum *p, double theta, double lenght, double fcons, double gconst, double mass);
extern void update_DampenedPendulum(struct DampenedPendulum *p, double dt);
extern void print_DampenedPendulum(struct DampenedPendulum *p, FILE *f, double t);


struct ElasticPendulum
{
    double mass;
    double lenght;
    double econst;
    double gconst;
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double theta;
    double omega;
    double alpha;
};

extern void init_ElasticPendulum(struct ElasticPendulum *p, double xPosition, double yPosition, double lenght, double econst, double gconst, double mass);
extern void update_ElasticPendulum(struct ElasticPendulum *p, double dt);
extern void print_ElasticPendulum(struct ElasticPendulum *p, FILE *f, double t);


#endif // PENDULUM_H_INCLUDED
