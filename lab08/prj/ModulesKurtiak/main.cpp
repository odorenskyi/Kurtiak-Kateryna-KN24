#include <iostream>
#include <cmath>
#include <stdexcept>

// Функція для обчислення S відповідно до формули варіанту 25
double s_calculation(double x, double y, double z) {
    return fabs(sqrt(fabs(z - 2 * x)) - x * sin(pow(x, 2 * z) * y));
}
