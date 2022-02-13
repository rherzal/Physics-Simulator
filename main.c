#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Projectile.h"
#include "Plotter.h"
#include "Pendulum.h"
#include "Planets.h"
int main()
{
    struct Plotter p;
    init_Plotter(&p, "data.csv");

    double t = 0;
    double dt = 0.01;
    double mt = 10;
    char input;
    double lenght, friction, gravitationalForce, mass, initialX, initialY, velX, velY;

    int X = 0;
    int Y = 0;


    while(input != "q")
    {
        FILE *f = fopen("data.csv", "w+");
        printf("Input what is the frame rate you want to calculate at. A higher frame rate will mean a higher accuracy but a slower computer.\nThe frame rate we recommend is 0.01 \n");
        scanf("%lf", &dt);
        printf("Choose the behaviour you want to simulate\nInput\n\t -'f' for projectile with friction \n\t -'p' for dampened pendulum \n\t -'n' for normal pendulum\n\t -'t' for a planet\n\t -'e' for a elastic pendulum\n\t -'q' to quit\n\t");
        fflush(stdin);
        scanf("%c", &input);
        if (input == 'q')
            break;
        switch(input)
        {

        case 'p':
        {
            printf("You have chosen dampened pendulum \n\t");
            printf("Input the lenght of the pendulum: ");
            scanf("%lf", &lenght);
            printf("\n\tInput the friction with the air: ");
            scanf("%lf", &friction);
            printf("\n\tInput gravitational force: ");
            scanf("%lf", &gravitationalForce);
            printf("\n\tInput the mass of the pendulum: ");
            scanf("%lf", &mass);
            printf("\n\tPlease choose the data to be plotted 1-time, 2-angle, 3-ang. vel., 4-ang.acc., 5-x, 6-y, 7-vx, 8-vy");
            printf("\n\tOn the X axis: ");
            scanf("%d", &X);
            printf("\n\tOn the Y axis: ");
            scanf("%d", &Y);

            struct DampenedPendulum dp;
            init_DampenedPendulum(&dp, 3.1415/4, lenght, friction, gravitationalForce, mass);
            for(t = 0; t <= 10; t += dt)
            {
                print_DampenedPendulum(&dp, f, t);
                update_DampenedPendulum(&dp, dt);
            }


        }
        break;
        case 'e':
        {
            printf("\n\tYou have chosen elastic pendulum");
            printf("\n\tInput the lenght of the pendulum: ");
            scanf("%lf", &lenght);
            printf("\n\tInput the spawn position of the object over x axis: ");
            scanf("%lf", &initialX);
            printf("\n\tInput the spawn position of the object over y axis: ");
            scanf("%lf", &initialY);
            printf("\n\tInput the mass of the pendulum: ");
            scanf("%lf", &mass);
            printf("\n\tPlease choose the data to be plotted 1-time, 2-angle, 3-x, 4-y, 5-vx, 6-vy");
            printf("\n\tOn the X axis: ");
            scanf("%d", &X);
            printf("\n\tOn the Y axis: ");
            scanf("%d", &Y);

            struct ElasticPendulum ep;
            init_ElasticPendulum(&ep, initialX, initialY, lenght, 5, 10, mass);

            for(t = 0; t <= 50; t += dt)
            {
                print_ElasticPendulum(&ep, f, t);
                update_ElasticPendulum(&ep, dt);
            }


        }
        break;
        case'f':
            {
                printf("You gave chosen projectile with friction\n\t");
                printf("Input the spawn position of the object over x axis: ");
                scanf("%lf", &initialX);
                printf("\n\tInput the spawn position of the object over y axis: ");
                scanf("%lf", &initialY);
                printf("\n\tInput the velocity over x: ");
                scanf("%lf", &velX);
                printf("\n\tInput the velocity over y: ");
                scanf("%lf", &velY);
                printf("\n\tInput the friction with the air: ");
                scanf("%lf", &friction);
                printf("\n\tInput the mass of the object: ");
                scanf("%lf", &mass);
                printf("\n\tPlease choose the data to be plotted 1-time, 2-x, 3-y, 4-vel. x, 5-vel. y");
                printf("\n\tOn the X axis: ");
                scanf("%d", &X);
                printf("\n\tOn the Y axis: ");
                scanf("%d", &Y);
                struct Projectile_With_Friction proj;
                init_Projectile_With_Friction(&proj, initialX, initialY, velX, velY, friction, mass);

                for(t = 0; t <= 10; t += dt)
        {
            print_Projectile_With_Friction(&proj, f, t);
                update_Projectile_With_Friction(&proj, dt);
            }


        }
        break;

        case 'n':
        {
            printf("You have chosen simple pendulum\n\t");
            printf("\n\tInput the lenght of the pendulum: ");
            scanf("%lf", &lenght);
            printf("\n\tInput the gravitational force: ");
            scanf("%lf", &gravitationalForce);
            printf("\n\tInput the mass of the pendulum: ");
            scanf("%lf", &mass);
            printf("\n\tPlease choose the data to be plotted 1-time, 2-angle, 3-ang. vel., 4-ang.acc., 5-x, 6-y, 7-vx, 8-vy");
            printf("\n\tOn the X axis: ");
            scanf("%d", &X);
            printf("\n\tOn the Y axis: ");
            scanf("%d", &Y);
            struct SimplePendulum dp;
            init_SimplePendulum(&dp, 3.1415/4,lenght, gravitationalForce, mass);
            for(t = 0; t <= 10; t += dt)
            {
                print_SimplePendulum(&dp, f, t);
                update_SimplePendulum(&dp, dt);
            }

        }
        break;
        case 't':
        {

            struct Planet planet;
            struct Star stars[2];

            init_Star(stars+0, 5, -1, 0);
            init_Star(stars+1, 5, 1, 0);

            printf("You have chosen Planets\n\t");
            printf("\n\tInput the mass of the planet: ");
            scanf("%lf", &mass);
            printf("\n\tInput the spawn position on the X axis of the planet: ");
            scanf("%lf", &initialX);
            printf("\n\tInput the spawn position on the Y axis of the planet: ");
            scanf("%lf", &initialY);
            printf("\n\tInput the velocity on the X axis of the planet: ");
            scanf("%lf", &velX);
            printf("\n\tInput the velocity on the Y axis of the planet: ");
            scanf("%lf", &velY);
            X = 1;
            Y = 2;
            init_Planet(&planet, mass, initialX, initialY, velX, velY);

            print_System(1, &planet, 2, stars, f, 0);
            for (t = 0; t < 10; t += dt)
            {
                print_System(1, &planet, 2, stars, f, t);
                update_System(1, &planet, 2, stars, 1, dt);
            }


        }
        break;
        default:
            break;
        }

        fclose(f);
        plot_Plotter(&p, X, Y);

    }


    return 0;
}
