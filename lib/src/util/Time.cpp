//
// Created by Jonas on 10/3/19.
//

#include "Time.h"

#include <chrono>

double Time::delta;

long Time::getTime() {
  std::chrono::time_point<std::chrono::high_resolution_clock> now = std::chrono::high_resolution_clock::now();
  auto duration = now.time_since_epoch();

  return std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
}

double Time::getDelta() {
  return delta;
}

void Time::setDelta(double d) {
  delta = d;
}