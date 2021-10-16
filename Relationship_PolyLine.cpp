#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Point{
    private:
    int x;
    int y;

    public:
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    void setX(int x){
        this->x = x;
    }
    int getX(){
        return x;
    }
    void setY(int y){
        this->y = y;
    }
    int getY(){
        return y;
    }
};

class PolyLine{
    private:
    vector<Point> points;

    public:
    PolyLine(){}
    PolyLine(vector<Point> points){
        this->points = points;
    }
    void appendPoint(Point point){
        points.push_back(point);
    }
    void appendPoint(int x, int y){
        points.push_back(Point(x,y));
    }
    double getLength(){
        double length = 0;
        for(int i = 0; i < points.size() - 1; i++){
            double d = sqrt(pow(points[i].getX() - points[i+1].getX(),2) + pow(points[i].getY() - points[i+1].getY(),2));
            length += d;
        }
        return length;
    }
};

int main(){
    Point point1(5,6), point2(4,2), point3(4,6), point4(6,9);
    vector<Point> points;
    points.push_back(point1);
    points.push_back(point2);
    points.push_back(point3);
    points.push_back(point4);
    PolyLine polyLine1(points);
    cout << polyLine1.getLength() << endl;

    PolyLine polyLine;
	polyLine.appendPoint(Point(1, 1));
	polyLine.appendPoint(Point(2, 3));
	polyLine.appendPoint(3, 0);
	polyLine.appendPoint(4, 2);
	cout << polyLine.getLength() << endl;
    return 0;
}