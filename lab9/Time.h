#ifndef Time_h
#define Time_h
#include <iostream>
#include <cmath>
//#include <math.h>
class Time {
//store a time expressed in hours, minutes and seconds
//also: Time::add(const Time & t) This method should add the time t to the object it is called from.
private:
  int hours;
  int minutes;
  int seconds;
public:
  Time();
  Time (int, int, int);
  int getHours(); //i removed const, because i keep getting errors
  int getMinutes();
  int getSeconds();
  void add(const Time & t);

  //extending Time class for exercise 2
  void getAngles(float& a, float& b, float& c);

  //extending Time class for exercise 3
  void getHourCoords(float& x, float& y);
  void getMinuteCoords(float& x, float& y);
  void getSecondsCoords(float& x, float& y);

};

Time::Time() { //default constructor
  hours = 0;
  minutes = 0;
  seconds = 0;
}

Time::Time(int hours, int minutes, int seconds) { //custom constructor
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
}

int Time::getHours() {
  return hours;
}

int Time::getMinutes() {
  return minutes;
}

int Time::getSeconds() {
  return seconds;
}
void Time::add(const Time & t) { //This method should add the time t to the object it is called from.
  //should increase hours, mins & secs using t, like t.<something>

/*  hours = t.hours;
  minutes = t.minutes;
  seconds = t.seconds;*/

  seconds += t.seconds;
  if(seconds >= 60) {
    seconds -= 60;
    minutes++;
  }

  minutes += t.minutes;
  if(minutes >= 60) { //no need to put >= (?)
    minutes -= 60;
    hours++;
  }
  hours += t.hours;
}

//for exercise 2
void Time::getAngles(float& a, float& b, float& c) { // a = hours, b = mins, c = secs
  //angles measured from x-axis: 3:00 = 0, 9:00 = pi, 12:00 = pi/2, 6:00 = -pi/2
  //secs and mins will move discreetly, while hour will be continuous

  //we need to use M_PI
  if (hours <= 3) {
    a = (M_PI/2) - ((hours * (M_PI/6)) + (minutes * (M_PI/360)));
  }
  else if (hours >= 9){
    a = (M_PI) - (((hours - 9) * (M_PI/6)) + (minutes*(M_PI/360)));
  }
  else {
    a = -1 * ((hours - 3) * (M_PI/6) + (minutes*(M_PI/360)));
  }

  //minutes
  if(minutes <= 15) {
    b = (M_PI/2) - (minutes*(M_PI/360));
  }
  else if (minutes >= 45) {
    b = (M_PI) * ((minutes - 45) * (M_PI/30));
  }
  else {
    b = -1 * (minutes - 15) * (M_PI/30);
  }

  //seconds, should be the same as minutes
  if (seconds <= 15) {
    c = (M_PI/2) - (seconds * (M_PI/30));
  }
  else if (seconds >= 45) {
    c = (M_PI) - ((seconds - 45) * (M_PI/30));
  }
  else {
    c = -1 * (seconds - 15) * (M_PI/30);
  }

}

//for exercise 3; use angles from the functions above (just copy them)
void Time::getHourCoords(float& x, float& y) {//returns point of intersections of hand w/the unit circle
  float a = 0; //hours from above
  if (hours <= 3) {
    a = (M_PI/2) - ((hours * (M_PI/6)) + (minutes * (M_PI/360)));
  }
  else if (hours >= 9){
    a = (M_PI) - (((hours - 9) * (M_PI/6)) + (minutes*(M_PI/360)));
  }
  else {
    a = -1 * ((hours - 3) * (M_PI/6) + (minutes*(M_PI/360)));
  }

  //then we use x = cos(theta) and y = sin(theta)
  x = cos(a);
  y = sin(a);

}

void Time::getMinuteCoords(float& x, float& y){
  float b = 0; //minutes from above
  if(minutes <= 15) {
    b = (M_PI/2) - (minutes*(M_PI/30)); // don't do M_PI/360. does not work
  }
  else if (minutes >= 45) { //we need a negative number here!
    b = (M_PI) - ((minutes - 45) * (M_PI/30)); //also do not multiply, M_PI, subtract it
  }
  else {
    b = -1 * (minutes - 15) * (M_PI/30);
  }

  //do sin and cos again
  x = cos(b);
  y = sin(b);
}

void Time::getSecondsCoords(float& x, float& y) {
  float c = 0; //seconds from above
  if (seconds <= 15) {
    c = (M_PI/2) - (seconds * (M_PI/30));
  }
  else if (seconds >= 45) {
    c = (M_PI) - ((seconds - 45) * (M_PI/30));
  }
  else {
    c = -1 * (seconds - 15) * (M_PI/30);
  }

  //sin and cos again
  x = cos(c);
  y = sin(c);
}
#endif
