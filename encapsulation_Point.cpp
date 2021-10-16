#include<iostream>
#include<math.h>
using namespace std;

class Point{
    private:
    double x;
    double y;
    
    public:
    Point(){

    }
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }

    void setX(double x){
        this->x = x;
    }
    double getX(){
        return x;
    }

    void setY(double y){
        this->y = y;
    }
    double getY(){
        return y;
    }
    void setXY(double x, double y){
        this->x = x;
        this->y = y;
    }
    double distance(double x, double y){
        return sqrt((this->x - x)*(this->x - x) + (this->y - y)*(this->y - y));
    }
    double distance(Point another){
        return distance(another.getX(), another.getY);
    }
};