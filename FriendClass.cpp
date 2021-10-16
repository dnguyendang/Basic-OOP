#include<iostream>
using namespace std;

//Lớp bạn cũng giống như hàm bạn là nó có thể truy cập các biến thành viên private của lớp kia.
// class A là bạn của class B nên tất cả hàm thành viên của lớp B là bạn của lớp A và chiều ngược lại thì không đúng.

#include <bits/stdc++.h>
using namespace std;

class B{
private:
	int b;
public:
	B()
	{
		b = 10;
	}
	friend class A;
};

class A{
public:
	void print(B arg)
	{
		cout<<arg.b;
	}
};
int main()
{
	B b;
	A a;
	a.print(b);
 return 0;
 }