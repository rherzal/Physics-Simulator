/*
###################################################################
||                                                               ||
||Projectile.h - Header file for the projectile simulation module||
||                        Copyright: 2021                        ||
||                         License:  MIT                         ||
||               Authors: Radu Herzal, Cocea Vlad                ||
||                                                               ||
||                                                               ||
###################################################################
*/


#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED

#include "Constants.h"

#include <stdio.h>

//structure definition of a Projectile
struct Projectile
{
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double mass;
};
//structure definition of a projectile with friction
struct Projectile_With_Friction
{
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
    double frictionCoefficient;
    double mass;
};

//initializes the parameters of a Projectile object using separate velocities for each axis
extern void     init_Projectile(struct Projectile *p, double posX, double posY, double velX, double velY, double m);
//initializes the parameters of a Projectile object using only one velocity and the angle of launch
extern void     init_Projectile_Angle(struct Projectile *p, double posX, double posY, double vel, double theta, double m);
//updates the parameters of a Projectile object using a time step dt
extern void     update_Projectile(struct Projectile *p, double dt);
//prints the parameters of a Projectile object at time t in a stream f
extern void     print_Projectile(struct Projectile *p, FILE *f, double t);

//initializes the parameters of a Projectile_With_Friction object using separate velocities for each axis
extern void     init_Projectile_With_Friction(struct Projectile_With_Friction *p, double posX, double posY, double velX, double velY, double frc, double m);
//initializes the parameters of a Projectile_With_Friction object using only one velocity and the angle of launch
extern void     init_Projectile_With_Friction_Angle(struct Projectile_With_Friction *p, double posX, double posY, double vel, double theta, double frc, double m);
//updates the parameters of a Projectile_With_Friction object using a time step dt
extern void     update_Projectile_With_Friction(struct Projectile_With_Friction *p, double dt);
//prints the parameters of a Projectile_With_Friction object at time t in a stream f
extern void     print_Projectile_With_Friction(struct Projectile_With_Friction *p, FILE *f, double t);


#endif // PROJECTILE_H_INCLUDED
