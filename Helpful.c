
#include <math.h>
#include "Helpful.h"

double distance(double x0, double y0, double x1, double y1)
{
    return sqrt(pow(x0 - x1, 2) + pow (y0 - y1, 2));
}

