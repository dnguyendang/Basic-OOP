#include <bits/stdc++.h>
using namespace std;
 
class phanso 
{
private:
    int tu, mau;
 
public:
    phanso()
    {
        tu = mau = 0;
    }
 
    ~phanso()
    {
        tu = mau = 0;
    }
    
    // nhap xuat binh thuong 
    void input()
    {
        cout << "Nhap tu so: ";
        cin >> this->tu;
        cout << "Nhap mau so: ";
        cin >> this->mau;
    }
 
    void output()
    {
        cout << this->tu << "/" << this->mau << endl;
    }
    
    //dinh nghia phep cong -> co the su dung luon ma khong can goi 
    // nap chong toan tu + cho lop phan so bang ham thanh vien 
    //bang cach nap chong toan tu 1 ngoi (chi co the truyen vao mot tham so)
    phanso operator +(phanso b)
    {
        phanso c;
        c.tu = this->tu * b.mau + this->mau * b.tu;
        c.mau = this->mau * b.mau;
        return c;
    }    
    
    // nap chong toan tu + cho lop phan so bang ham ban
    // bang cach nap chong toan tu 2 ngoi (truyen vao 2 tham so)
    // friend phanso operator +(phanso a, phanso b)
    // {
    //     phanso c;
    //     c.tu = a.tu * b.mau + a.mau * b.tu;
    //     c.mau = a.mau * b.mau;
    //     return c;
    // }    

    // nap chong toan tu nhap xuat 
    friend istream &operator>>(istream &is, phanso &obj)
    {
        cout << "Nhap tu so: ";
        is >> obj.tu;
        cout << "Nhap mau so: ";
        is >> obj.mau;
        return is;
    }
    
    friend ostream &operator<<(ostream &os, phanso obj)
    {
        os << obj.tu << "/" << obj.mau << endl;
        return os;
    }
};
 
int main()
{
    phanso a, b, c;
 
    // goi ham nhap xuat binh thuong
    a.input();
    b.input();

    c = a + b;  c.output();
    // su dung nap chong toan tu nhap xuat 
    phanso d;
    cin >> d;
    cout << d;
}