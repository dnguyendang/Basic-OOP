#include<iostream>
using namespace std;

class Math{
public:
	static double getPI(){
		return 3.14;
	}
};

int main(){
	cout << Math::getPI() << endl;
	cout << "alo alo" << endl;
	printf (" hello ");
	return 0;
}