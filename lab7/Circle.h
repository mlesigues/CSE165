#ifndef Circle_h
#define Circle_h
#include <cmath>

class Circle {
 //3 private variables
  double x; //cartesian
  double y; //cartesian
  double r; //radius

public:
  double area; //area of the circle

  //default constructor
  Circle () {
    x = 0.0;
    y = 0.0;
    r = 1.0;
    area = M_PI * r * r;
  }

  Circle(double x, double y, double r) {
    this->x = x;
    this->y = y;
    this->r = r;
    area = M_PI * r * r;
  }


  double getX() const {
    return x;
  }

  double getY() const {
    return y;
  }

  double getR() const {
    return r;
  }

  /*double getArea() const {
    return area;
  }*/

  void setX(double x) {
    this->x = x;
  }

  void setY(double y) {
    this->y = y;
  }

  void setR(double r) {
    this->r = r;
    this->area = M_PI * r * r;
  }

 /*void setArea(double area) {
    this->area = area;
  }*/

};


#endif
