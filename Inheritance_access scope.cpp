#include<iostream 
using namespace std;

class A {
public:
int x;
protected:
int y;
private:
int z;
};

class B : public A {
    // x: public
    // y: protected
    // z is private so it cannot be accessed from B class
};

class C : protected A {
    // x: protected
    // y: protected
    // z is private so it cannot be accessed from C class
};

class D : private A {
    // x: private
    // y: private
    // z is private so it cannot be accessed from D class
}