#include<iostream>
using namespace std;

class Point{
    static int count; // bien tinh dung nhu 1 bien chung cho ham, duoc khai bao ngoai class
    Point(){
        count++;
    }
    void display(){
        cout << count;
    }
};

// count khoi tao bang toan tu ten va toan tu phan giai pham vi ben ngoai class 
int Point::count = 0;
int main(){
    Point p1, p2, p3, p4;
    p4.display();
    return 0;
}