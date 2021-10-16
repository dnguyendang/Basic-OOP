#include<iostream>
using namespace std;

class A{
    int x;
    public:
    A():x(2){} // constructor vs tham so x = 2 // goi la ham tao 1 tham so 
    void funcA(){
        cout << "x = " << x;
    }
};

class B : private A{ // toan bo attributes  va methods cua A tro thanh private
    int y;
    public:
    B():y(3){} // constructor va tham so y = 3
    void funcA(){
        A::funcA();
        cout<< "y = " << y;
    }
};

int main(){
    B* b = new B();
    b->funcA();
}