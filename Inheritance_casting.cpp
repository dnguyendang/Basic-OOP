#include<iostream>
using namespace std;

class Person{
    // content of Person
    
    // virtual void foo() {}
    // if we wanna use a dynamic cast to downcast, base class must be abstract, it must have at least one virtual fuction 
};

class Employee : public Person{
    public:
    Employee(string fName, string lName, double sal){
        FirstName = fName;
        LastName = lName; 
        salary = sal; 
    }
    string FirstName;
    string LastName;
    double salary;

    void show(){
        cout << "First Name: " << FirstName << " Last Name: " << LastName << " Salary: " << salary << endl;
    }
    void addBonus(double bonus){
        salary += bonus;
    }
};

class Manager : public Employee{
    public:
    Manager(string fName, string lName, double sal, double comm) : Employee(fName, lName, sal){
        Commision = comm;
    }
    double Commision;
    double getComm(){
        return Commision;
    }
};

class Clerk : public Employee{
    public:
    Clerk(string fName, string lName, double sal, Manager* man) : Employee(fName, lName, sal){
        manager = man;
    }
    Manager* manager;
    Manager* getManager(){
        return manager;
    }
};

// one of the biggest advantages of upcasting is the ability to write generic function for all derived classes from the same base class 
void congratulate(Employee * emp){
    cout << "Happy Birthday!!!" << endl;
    emp->addBonus(200);
    emp->show();
};

int main(){
    // pointer to base class object
    Employee* emp;

    // object of derived class
    Manager m1("Steve", "Kent", 3000, 0.2);
    Clerk c1("Kevin", "Jones", 1000, &m1);

    // cout << m1.FirstName << endl;
    // m1.show();
    // cout << m1.getComm() << endl;

    //implicit up-casting
    emp = &m1;

    //It's ok 
    cout << emp->FirstName << endl;
    cout << emp->salary << endl;
    //Fails because upcasting is used
    // cout << emp->getComm();

    congratulate(&c1);
    congratulate(&m1);

    cout << "Manager of " << c1.FirstName << " is " << c1.getManager()->FirstName << endl;

    //down-casting
    Manager* m2 = (Manager*)(emp);
    // so what happens if we try to downcast a base class pointer to object of base class instead of object of derived class
    Employee e1("Peter", "Green", 1400);
    // try to cast an employee to Manager
    Manager* m3 = (Manager*)(&e1);
    cout << m3->getComm() << endl;
    // an unexpected result bcs e1 is not object of Manager class. It doesn't contain any information about commissions

    // dynamic_cast
    // Employee e2("Black", "Pink", 2000);
    // Manager* m4 = dynamic_cast<Manager*>(&e2);
    // if (m4)
    // cout << m4->getComm() << endl;
    // else
    // cout << "Can't  cast from Employee to Manager" << endl;

    return 0;
}

// con trỏ của lớp cơ sở trỏ vào lớp cơ sở khác nhưng ở đây, con trỏ lớp cơ sở được sở dụng như con trỏ của lớp dẫn xuất -> đây gọi là sự đa hình liên quan đến kế thừa trong c++ 

// up-casting 
// is the process of creating a pointer or reference of the derived class object as a base class pointer 
// -> gan con tro lop dan xuat cho con tro lop co so 
// when upcasting -> can only access to attributes and methods which determined in base class

// down-casting la qua trinh chuyen doi con tro lop co so thanh con tro lop dan xuat.
// viec downcasting phai thuc hien thu cong, phai chi dinh typecast ro rang
// downcasting is not safe like upcasting <- a devired class object can always be thought of as a base class objct, however, the opposite is not true

// dynamic_cast is an operator that safely converts one type to another.
// in case, the conversation is possible and safe, it returns the address of the converted object. Otherwise it returns NULLptr
