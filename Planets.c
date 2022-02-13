#include "Planets.h"

void init_Planet(struct Planet *p, double mass, double positionX, double positionY, double velocityX, double velocityY)
{
    p->mass = mass;
    p->positionX = positionX;
    p->positionY = positionY;
    p->velocityX = velocityX;
    p->velocityY = velocityY;
    p->accelerationX = 0;
    p->accelerationY = 0;
}

void init_Star(struct Star *s, double mass, double positionX, double positionY)
{
    s->mass = mass;
    s->positionX = positionX;
    s->positionY = positionY;
}

void update_System(int nPlanet, struct Planet *p, int nStar, struct Star s[], double gconst, double dt)
{
    int i = 0;
    int j = 0;
    int k = 0;
    double force = 0.0;
    double alpha = 0.0;
    for (i = 0; i < nPlanet; i++)
    {
        (p+i)->accelerationX = 0;
        (p+i)->accelerationY = 0;
        for (j = 0; j < nPlanet; j++)
        {
            if (i != j)
            {
                force = gconst * (p+i)->mass * (p+j)->mass / pow(distance((p+i)->positionX, (p+i)->positionY, (p+j)->positionX, (p+j)->positionY), 2);
                alpha = atan2((p+j)->positionY - (p+i)->positionY, (p+j)->positionX - (p+i)->positionX);
                (p+i)->accelerationX += force * cos(alpha);
                (p+i)->accelerationY += force * sin(alpha);
            }
        }
        for (k = 0; k < nStar; k++)
        {
            force = gconst * (p+i)->mass * (s+k)->mass / pow(distance((p+i)->positionX, (p+i)->positionY, (s+k)->positionX, (s+k)->positionY), 2);
            alpha = atan2((s+k)->positionY - (p+i)->positionY, (s+k)->positionX - (p+i)->positionX);
            (p+i)->accelerationX += force * cos(alpha);
            (p+i)->accelerationY += force * sin(alpha);
        }
        (p+i)->velocityX += (p+i)->accelerationX * dt;
        (p+i)->velocityY += (p+i)->accelerationY * dt;
        (p+i)->positionX += (p+i)->velocityX * dt;
        (p+i)->positionY += (p+i)->velocityY * dt;
    }
}

void print_System(int nPlanet, struct Planet *p, int nStar, struct Star *s, FILE *f, double t)
{
    for (int i = 0; i < nPlanet; i ++)
    {

    }
}
