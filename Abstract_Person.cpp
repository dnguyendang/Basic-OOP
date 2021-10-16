#include<iostream>
using namespace std;

// an abstract class is a class that has at least one abstract method.
class Person{
    private:
    string name;
    string address;

    public:
    Person(string name, string address){
        this->name = name;
        this->address = address;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setAddress(string address){
        this->address = address;
    }
    string getAddress(){
        return address;
    }
    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Employee: public Person{
    private:
    int salary;

    public:
    Employee(string name, string address, int salary): Person(name, address){
        this->salary = salary;
    }
    void display(){
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};

class Customer: public Person{
    private:
    int balance;

    public:
    Customer(string name, string address, int balance): Person(name, address){
        this->balance = balance;
    }
    void display(){
        Person::display();
        cout << "Balance: " << balance << endl;
    }
};

int main() {
	Person *person1 = new Employee("Trung", "HN", 3300);
	Person *person2 = new Customer("Linh", "BN", 10400);
	person1->display();
	person2->display();
	return 0;
}