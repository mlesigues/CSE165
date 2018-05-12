#ifndef GenerateCircleData_h
#define GenerateCircleData_h

#include "Vec.h"

void generateCircleData(std::vector<Vec*>& points, const Vec& center, float radius, int resolution){
    // Clear the points vector to make sure it's empty before you start
    points.clear();
    
    // Provide the rest of the code here...
	//math 23 stuff: (x,y) = (r cos theta, r sin theta), r = radius ???
	//is resolution == theta??
	
	const double PI = 3.14159; //maybe just use M_PI instead of this?

	for(double angle = 0; angle <= 2*PI; angle += 2 * PI/resolution) {
		//points(center.getX() + radius*cos(angle), points(center.getY() + radius*sin(angle));
		double x = center.getX() + radius*cos(angle);
		double y = center.getY() + radius*sin(angle);
		//have to use push_back here, maybe i can use append?? but we have a vector, smh
		points.push_back(new Vec(x, y));
	}

	/*for (int i = 0; i < 360; i++) { //can't access x & y because they are private
		points(center.getX() + radius*cos(i), center.getY() + radius*sin(i));
	}*/
	
}

#endif
