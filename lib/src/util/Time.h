//
// Created by Jonas on 10/3/19.
//

#ifndef INC_3D_ENGINE_TIME_H
#define INC_3D_ENGINE_TIME_H

class Time {
 public:

  static const long SECOND = 1000000000;

  static long getTime();
  static double getDelta();
  static void setDelta(double d);

 private:

  static double delta;
};

#endif //INC_3D_ENGINE_TIME_H
