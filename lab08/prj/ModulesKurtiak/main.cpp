#include <iostream>
#include <cmath>
#include <stdexcept>

double s_calculation(double x, double y, double z) {
    return fabs(sqrt(fabs(z - 2 * x)) - x * sin(pow(x, 2 * z) * y));
}
