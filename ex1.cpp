#include<iostream>
using namespace std;

class Base{
    public:
    virtual void display(){ 
        cout << "Base" << endl;
    }
    // virtual nen ham se xac dinh doi tuong khi runtime  -> display() se la display() cua d.display()
    // neu khong co virtual thi se goi display cua base vi no dc xac dinh trc thoi diem bien dich 
    void show(){
        display();
    }
};

class Derive: public Base{
    public:
    void display(){
        cout << "Derive" << endl;
    }
};

int main(){
    Derive d;
    d.show();
    return 0;
}