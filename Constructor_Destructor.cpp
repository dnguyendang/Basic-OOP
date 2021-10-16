#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout << "A";
    }
    ~A(){
        cout << "B";
    }
};

class B: public A{
    public: 
    B():A(){
        cout << "C";
    }
    ~B(){
        cout <<"D";
    }
};

void arg(B &b){} //tham chieu -> dung truc tiep b 
void arg2(B b){} // copy qua 1 cai bien duoc khoi tao moi khac 
A a; // bien toan cuc -> duoc khoi tao tu dau va duoc huy khi ket thuc chuong trinh 

int main(){
    B b;
    // B ke thua A -> khi khai bao bien B b 
    //thi chuong trinh se khoi tao 1 bien A trc va chay cac ham ben trong A ( ngoai tru ham destructor) roi den B
    //do A la ham cha, B la ham con nen sau khi B bi huy chuong trinh moi huy A

    arg(b); // tham chieu
    //tham chieu khong khoi tao bien moi nen khi thoai khoi ham void khong phai goi ham huy 
    //muc dich ham huy de xoa khi khoi tao dia chi moi 
    //(giu nguyen moi thay doi cua b khi thoai khoi ham nen khong destructor)
    //-> in ra ACDB

    // cout << endl;
    // B b1; 
    // arg2(b1); 
    // in ra ACBDBD 

    return 0;
}