#ifndef Rect_h
#define Rect_h

struct Rect {
    float x;
    float y;
    float width;
    float height;
    
    Rect(float x, float y, float width, float height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    
    bool contains(float x, float y) {
        if ((this->x <= width-x) && (this->x <= x) && (this->y >= y) && (this->y <= height+y))
            return true;
        else
            return false;
    }
    ~Rect(){
        
    }
};

#endif /* Rect_h */
