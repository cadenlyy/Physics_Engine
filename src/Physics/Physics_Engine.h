#pragma once

#include <queue>
#include <string>

#include "Vec2d.h"
#include "Objects.h"

extern void test(Ball& Ball1, double s, std::string);
extern void ball_terminal_velocity(Ball& ball1, double s, std::string);
extern void thrown_ball(Ball& ball1, double s, std::string);
static void single_pendulum_period(Simple_pendulum pendulum1, ppd& Positions);
extern void single_pendulum(Simple_pendulum& Pendulum1, double s, std::string);
extern void double_pendulum(Complex_pendulum& Pendulum2, double s, std::string);
extern void constraint(Multi& MultiObjs, double s, std::string);