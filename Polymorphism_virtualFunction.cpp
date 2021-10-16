#include<iostream>
using namespace std;

// check virtual function
class baseClass
{
public:
  baseClass(int val) :someValue(val)
  {
  }
  virtual void info()
  {
    cout << "Info member function of base class" << endl;
  }
protected:
  int someValue;
};
class derivedClass1 : public baseClass
{
public:
  derivedClass1(int val) :baseClass(val)
  {
  }
  void info()
  {
    cout << "Info member function of derived class 1" << endl;
  }
};
class derivedClass2 : public baseClass
{
public:
  derivedClass2(int val) :baseClass(val)
  {
  }
  void info()
  {
    cout << "Info member function of derived class 2" << endl;
  }
};

// check virtual destrector 
class A
{
public:
  virtual ~A()
  {
    cout << "Base class destructor" << endl;
  }
};
class B : public A
{
public:
  ~B()
  {
    cout << "B class destructor" << endl;
  }
};

int main(){
// test virtual function
    derivedClass1 child1(1);
    derivedClass2 child2(2);

    //pointers to base class
    baseClass* basePtr1;
    baseClass* basePtr2;

    //make pointers to base class point to objects of derived classes
    basePtr1 = &child1;
    basePtr2 = &child2;

    //calling info function
    basePtr1->info();
    basePtr2->info();

    //calling info function when we dont use virtual 
    basePtr1->info();
    basePtr2->info();

    //use static cast and call info from derived class 1
    static_cast<derivedClass1*> (basePtr1)->info();
// test virtual destructor
    A* a = new B;
    // if we dont use keyword "virtual", b hasn't been deleted.
    delete a;
    return 0;
}

