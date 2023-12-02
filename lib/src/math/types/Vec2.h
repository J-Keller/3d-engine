//
// Created by Jonas on 6/30/23.
//

#ifndef MCCLONE_VEC2_H
#define MCCLONE_VEC2_H

template<class T>
class Vec2 {
 public:
  Vec2(T x, T y);

  T x;
  T y;
};

template<class T>
Vec2<T>::Vec2(T x, T y) {
  this->x = x;
  this->y = y;
}

// Operator overloads
template<class T>
bool operator==(Vec2<T> a, Vec2<T> b) {
  return a.x == b.x && a.y == b.y;
}

template<class T>
bool operator!=(Vec2<T> a, Vec2<T> b) {
  return a.x != b.x || a.y != b.y;
}

template<class T>
Vec2<T> operator+(Vec2<T> a, Vec2<T> b) {
  return Vec2<T>(a.x + b.x, a.y + b.y);
}

// Dot product
template<class T>
T operator*(Vec2<T> a, Vec2<T> b) {
  return a.x * b.x + a.y * b.y;
}

template<class T>
Vec2<T> operator*(Vec2<T> a, T b) {
  return Vec2<T>(a.x * b, a.y * b);
};

template<class T>
Vec2<T> operator/(Vec2<T> a, T b) {
  return Vec2<T>(a.x / b, a.y / b);
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;

#endif //MCCLONE_VEC2_H
