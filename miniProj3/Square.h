#ifndef Square_h
#define Square_h

// is it X or O
enum shape{Undetermined = 0, X = 1, O = 2};

class Square {
	float xcoord;
	float ycoord;
	float length;
	float width;
	float xcent;
	float ycent;
	//X or O
	shape object;
	float red;
	float green;
	float blue;

public:
	//Default Constructor
	Square();
	//Customized Constructor
	Square(float x, float y);

	//Setters
	void setShape(shape object);
	void setColors(float r, float g, float b);

	//Getters
	float getX();
	float getY();
	float getXcent();
	float getYcent();
	shape getShapeType();
	float getRed();
	float getGreen();
	float getBlue();

	 //add the bool contains that we did on the previous lab
	bool contains(float mx, float my);

}; //important

#endif
