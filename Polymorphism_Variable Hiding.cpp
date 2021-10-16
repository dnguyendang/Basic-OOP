#include<iostream>
using namespace std;

class SuperClass{
    public:
    int x = 10;

    virtual void display(){
        cout << x << endl;
    }
};

class SubClass: public SuperClass{
    public:
    int x = 20;

    void display(){
        cout << x << endl;
    }
};

int main(){
    SuperClass* s = new SubClass();
    cout << s->x << endl;
    s->display();
    return 0;
}

//thuoc tinh cua lop cha se khong bi lop con ghi de ma bi lop con an di -> x thuoc lop con va x thuoc lop cha la 2 thuoc tinh doc lop 
//