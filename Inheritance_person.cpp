#include <iostream>
#include <math.h>
using namespace std;

class Person {
    private:
    string name;
    string gender;

    public:
    Person(string name, string gender){
        this->name = name;
        this->gender = gender;
    }

    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    string getGender(){
        return gender;
    }
    void setGender(string gender){
        this->gender = gender;
    }

    void display(){
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Student : public Person {
    private:
    long salary;

    public:
    // Student() : Person("Viet", "M"){
    // }
    Student(string name, string gender, long salary) : Person(name, gender){
        this->salary = salary;
    }

    long getSalary(){
        return salary;
    }
    void setSalary(long salary){
        this->salary = salary;
    }
    void display(){
        Person::display();
        cout << "Salary: " << salary << endl;
    }
};

class Teacher : public Student{
    private:
    long bonus;
    public:
    Teacher(string name , string gender,long salary, long bonus) : Student(name, gender, salary){
        this->bonus = bonus;
    }

    long getBonus(){
        return bonus;
    }
    void setBonus(int bonus){
        this->bonus = bonus;
    }
    long getSalary(){
        return Student::getSalary()+bonus;
    }

    void display(){
        Person::display();
        cout << "Salary: " << getSalary() << endl;
    }
};
 
// test 
int main(){
    Student s("Trung", "M", 50);
    s.display();
    Teacher t("Thanh", "F", 500 ,20);
    t.display();
    return 0;
}