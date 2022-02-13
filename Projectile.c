/*
##########################################################
||                                                      ||
||Projectile.c - See Projectile.h for copyright and info||
||                                                      ||
||                                                      ||
##########################################################
*/


#include "Projectile.h"
#include <math.h>

void init_Projectile(struct Projectile *p, double posX, double posY, double velX, double velY, double m)
{
    p->positionX = posX;
    p->positionY = posY;
    p->velocityX = velX;
    p->velocityY = velY;
    p->mass = m;
}

void init_Projectile_Angle(struct Projectile *p, double posX, double posY, double vel, double theta, double m)
{
    p->positionX = posX;
    p->positionY = posY;
    p->velocityX = vel * cos(theta);
    p->velocityY = vel * sin(theta);
    p->mass = m;
}

void update_Projectile(struct Projectile *p, double dt)
{
    //it integrates the functions in discrete time intervals using Riemann sums
    if (p->positionY < 0)
    {
        p->velocityY = -p->velocityY;
        p->positionY = 0;
    }


    p->positionX += p->velocityX * dt;
    p->velocityY += G * dt;
    p->positionY += p->velocityY * dt;




}

void print_Projectile(struct Projectile *p, FILE *f, double t)
{
    fprintf(f, "%f, %f, %f, %f, %f\n", t, p->positionX, p->positionY, p->velocityX, p->velocityY);
}

void init_Projectile_With_Friction(struct Projectile_With_Friction *p, double posX, double posY, double velX, double velY, double frc, double m)
{
    p->positionX = posX;
    p->positionY = posY;
    p->velocityX = velX;
    p->velocityY = velY;
    p->frictionCoefficient = frc;
    p->mass = m;
}

void init_Projectile_With_Friction_Angle(struct Projectile_With_Friction *p, double posX, double posY, double vel, double theta, double frc, double m)
{
    p->positionX = posX;
    p->positionY = posY;
    p->velocityX = vel * cos(theta);
    p->velocityY = vel * sin(theta);
    p->frictionCoefficient = frc;
    p->mass = m;
}

void update_Projectile_With_Friction(struct Projectile_With_Friction *p, double dt)
{
    //it integrates the functions in discrete time intervals using Riemann sums
    //uses the law friction force ~ v^2
    //the if statements are used to decide the sign of the friction force

    if (p->positionY < 0)
    {
        p->velocityY = -p->velocityY;
        p->positionY = 0;
    }

    if (p->velocityX >= 0)
        p->velocityX += -(p->frictionCoefficient * (p->velocityX * p->velocityX) / p->mass) * dt;
    else
        p->velocityX += (p->frictionCoefficient * (p->velocityX * p->velocityX) / p->mass) * dt;
    p->positionX += p->velocityX * dt;
    if (p->velocityY >= 0)
        p->velocityY += (G * dt - (p->frictionCoefficient * (p->velocityY * p->velocityY) / p->mass * dt));
    else
        p->velocityY += (G * dt + (p->frictionCoefficient * (p->velocityY * p->velocityY) / p->mass * dt));
    p->positionY += p->velocityY * dt;
}

void print_Projectile_With_Friction(struct Projectile_With_Friction *p, FILE *f, double t)
{
    fprintf(f, "%f, %f, %f, %f, %f\n", t, p->positionX, p->positionY, p->velocityX, p->velocityY);
}
