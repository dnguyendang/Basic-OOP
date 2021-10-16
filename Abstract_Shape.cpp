#include<iostream>
using namespace std;

class Shape{
    public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class Rectangle : public Shape{
    private:
    double length;
    double width;

    public:
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }
    double getArea(){
        return length*width;
    }
    double getPerimeter(){
        return 2*(length + width);
    }
};

class Circle : public Shape{
    private:
    double radius;

    public:
    Circle(double radius){
        this->radius = radius;
    }
    double getArea(){
        return 3.14*radius*radius;
    }
    double getPerimeter(){
        return 2*3.14*radius;
    }
};

void display(Shape* shape){
    cout << "Area: " << shape->getArea() << endl;
    cout << "Perimeter: " << shape->getPerimeter() << endl;
}

int main() {
    Shape** shapes = new Shape * [3];
    shapes[0] = new Rectangle(3.4, 5.3);
    shapes[1] = new Circle(5.5);
    shapes[2] = new Rectangle(7.4, 4.3);
    for (int i = 0; i < 3; i++) {
        display(shapes[i]);
    }
    return 0;
}