//
// Created by Jonas on 10/3/19.
//

#ifndef INC_3D_ENGINE_TIME_H
#define INC_3D_ENGINE_TIME_H

class Time {
 public:

  /**
   * One second in nanoseconds
   */
  static const long SECOND = 1000000000;

  /**
   * getTime
   *
   * get the current time
   *
   * @return current time in nanoseconds
   */
  static long getTime();

  /**
   * getDelta
   *
   * get the current delta value
   *
   * @return current delta value
   */
  static double getDelta();

  /**
   * setDelta
   *
   * set the current delta value
   */
  static void setDelta(double d);

 private:

  static double delta;
};

#endif //INC_3D_ENGINE_TIME_H
