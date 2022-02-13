#include "Pendulum.h"



void init_SimplePendulum(struct SimplePendulum *p, double theta, double lenght, double gconst, double mass)
{
    p->theta = theta;
    p->lenght = lenght;
    p->gconst = gconst;
    p->mass = mass;


    p->positionX = lenght * sin(theta);
    p->positionY = -lenght * cos(theta);

    p->velocityX = 0;
    p->velocityY = 0;
    p->omega = 0;
    p->alpha = 0;
}

void update_SimplePendulum(struct SimplePendulum *p, double dt)
{
    p->alpha = -p->gconst * sin(p->theta) / p->lenght;
    p->omega += p->alpha * dt;
    p->theta += p->omega * dt;


    p->positionX = p->lenght * sin(p->theta);
    p->positionY = -p->lenght * cos(p->theta);

    p->velocityX = p->omega * p->lenght * cos(p->theta);
    p->velocityY = p->omega * p->lenght * sin(p->theta);
}

void print_SimplePendulum(struct SimplePendulum *p, FILE *f, double t)
{
    fprintf(f, "%f, %f, %f, %f, %f, %f, %f, %f \n", t, p->theta, p->omega, p->alpha, p->positionX, p->positionY, p->velocityX, p->velocityY);
}


void init_DampenedPendulum(struct DampenedPendulum *p, double theta, double lenght, double fconst, double gconst, double mass)
{
    p->theta = theta;
    p->lenght = lenght;
    p->gconst = gconst;
    p->fconst = fconst;
    p->mass = mass;


    p->positionX = lenght * sin(theta);
    p->positionY = -lenght * cos(theta);

    p->velocityX = 0;
    p->velocityY = 0;
    p->omega = 0;
    p->alpha = 0;
}

void update_DampenedPendulum(struct DampenedPendulum *p, double dt)
{
    p->alpha = -p->gconst * sin(p->theta) / p->lenght;


    p->alpha -= p->omega * p->fconst / p->mass;

    p->omega += p->alpha * dt;
    p->theta += p->omega * dt;


    p->positionX = p->lenght * sin(p->theta);
    p->positionY = -p->lenght * cos(p->theta);

    p->velocityX = p->omega * p->lenght * cos(p->theta);
    p->velocityY = p->omega * p->lenght * sin(p->theta);
}

void print_DampenedPendulum(struct DampenedPendulum *p, FILE *f, double t)
{
    fprintf(f, "%f, %f, %f, %f, %f, %f, %f, %f \n", t, p->theta, p->omega, p->alpha, p->positionX, p->positionY, p->velocityX, p->velocityY);
}




void init_ElasticPendulum(struct ElasticPendulum *p, double xPosition, double yPosition, double lenght, double econst, double gconst, double mass)
{
    p->theta = atan2(xPosition, (-yPosition));
    p->alpha = 0;
    p->econst = econst;
    p->gconst = gconst;
    p->lenght = lenght;
    p->mass = mass;
    p->omega = 0;
    p->positionX = xPosition;
    p->positionY = yPosition;
    p->velocityX = 0;
    p->velocityY = 0;
}

void update_ElasticPendulum(struct ElasticPendulum *p, double dt)
{
    p->theta = atan2(p->positionX, (-p->positionY));
    double elasticForce = p->econst * (distance(p->positionX, p->positionY, 0, 0 ) - p->lenght);
    double accelerationX = 0;
    double accelerationY = 0;
    p->omega = distance(p->velocityX, p->velocityY, 0, 0) * sin(atan2(p->velocityX, p->velocityY)) / distance(p->positionX, p->positionY, 0, 0);
    double centrifugalForce = pow(p->omega, 2) / distance(p->positionX, p->positionY, 0, 0);


    accelerationY += -(p->gconst);
    accelerationY += elasticForce * cos(p->theta) / p->mass;
    accelerationX += -elasticForce *sin(p->theta) / p->mass;

    accelerationX += centrifugalForce * sin(p->theta) / p->mass;
    accelerationY += -centrifugalForce * cos(p->theta) / p->mass;

    p->velocityX += accelerationX * dt;
    p->velocityY += accelerationY * dt;

    p->positionX += p->velocityX * dt;
    p->positionY += p->velocityY * dt;

}

void print_ElasticPendulum(struct ElasticPendulum *p, FILE *f, double t)
{
    fprintf(f, "%f, %f, %f, %f, %f, %f\n",t , p->theta, p->positionX, p->positionY, p->velocityX, p->velocityY);
}
