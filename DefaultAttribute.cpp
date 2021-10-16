#include<iostream>
using namespace std;

class A{
    // public:
    int x;
    int y;
    // neu khong khai bao private public hay protected thi
    // mac dinh cua thuoc tinh cua lop la private
};

class B{
    public:
    A a;
    void input(){
        cout << "Enter x, y";
        cin >> a.x >> a.y ;
    }
};

int main(){
    B b;
    b.input();
    // chuong trinh bao loi khong truy cap dc vao bien x, y cua lop a do nam o pham vi truy cap private
}