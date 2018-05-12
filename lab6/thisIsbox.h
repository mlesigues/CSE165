#ifdef thisIsbox_h
#define thisIsbox_h

//this is the box header
class ThisBox {
private:
  float x;
  float y;
  float w;
  float h;
  int checking; //this check if box is occupied or not

public:
  ThisBox();
  ThisIsBox (float xSide, float ySide, float widthSide, float heightSide);
  /*  float xSide = 0.0;
    float ySide = 0.0;
    float widthSide = 0.0;
    float heightSide = 0.0;*/
  ~ThisBox();

  //we need getters and setters for everyone
  float getX();
  float getY();
  float getW();
  float getH();
  bool contains(float x, float y);
  bool setChecking(int i); //returns true if setChecking is allowed
  int getCheck();
  void reset(); //resets everything
  /*float setX();
  float setY();
  float setWidth();
  float setHeight();
  int setCheck();*/

};
