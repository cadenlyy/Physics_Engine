#include <vector>

#include "Force.h"
#include "constants.h"
#include "Objects.h"

extern double fball_y(double t, std::vector<double> v, Ball ball1) {
    double weight = ball1.Mass * g;
    double air_resistance = (p * (2 * PI * ball1.Radius * ball1.Radius) * c * v[0] * v[0]) / 2;
    double bouyancy = -(p * g * ((4 / 3) * PI * ball1.Radius * ball1.Radius * ball1.Radius));
    double force = weight + air_resistance + bouyancy;
    return force / ball1.Mass;
}

extern double  fball_x(double t, std::vector<double> v, Ball ball1) {
    double air_resistance = -(p * (2 * PI * ball1.Radius * ball1.Radius) * c * v[0] * v[0]) / 2;
    return air_resistance / ball1.Mass;
}

extern double  fsimple_pendulum(double t, std::vector<double>v, Simple_pendulum Pendulum1) {
    return (g * sin(v[1])) / Pendulum1.Length;
}

extern double fdouble_pendulum_1(double t, std::vector<double>v, complex_pendulum pendulum2) {
    // v1, p1, a1, v2, p2, a2
    return (-pendulum2.mass2 * pendulum2.length2 * v[6] * cos(v[1] - v[4]) + pendulum2.mass2 * pendulum2.length2 * v[0] * v[3] * sin(v[1] - v[4]) - pendulum2.mass2 * pendulum2.length2 * pow(v[3], 2) * sin(v[1] - v[4]) - pendulum2.mass2 * pendulum2.length2 * v[0] * v[3] * sin(v[1] - v[4]) + pendulum2.mass1 * g * sin(v[1]) + pendulum2.mass2 * g * sin(v[1])) / (pendulum2.mass1 * pendulum2.length1 + pendulum2.mass2 * pendulum2.length1);
}

extern double fdouble_pendulum_2(double t, std::vector<double>v, complex_pendulum pendulum2) {
    //v2, p2, a2, v1, p1, a1
    return (-pendulum2.length1 * v[5] * cos(v[4] - v[1]) + pendulum2.length1 * pow(v[3], 2) * sin(v[4] - v[1]) + g * sin(v[1])) / pendulum2.length2;
}