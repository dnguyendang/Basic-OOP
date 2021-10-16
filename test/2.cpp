#include<iostream>
#include<vector>

using namespace std;

class Person{
    private:
    string name;
    int age;
    string add;
    string tel;
    string sex;
    
    public:
    Person(){}
    Person(string name, int age, string add, string tel, string sex){
        this->name = name;
        this->age = age;
        this->add = add;
        this->tel = tel;
        this->sex = sex;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getAdd(){
        return add;
    }
    string getTel(){
        return tel;
    }
    string getSex(){
        return sex;
    }
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Add: " << add << endl;
        cout << "Tel: " << tel << endl;
    }
    virtual long salary() = 0;
    static vector<Person*> findPerson(vector<Person*> p){
        vector<Person*> v;
        for (int i = 0; i < p.size();i++){
            if(p[i]->add == "HN"){
                v.push_back(p[i]);
            }
        }
        return v;
    }
};


class EmployeePT : public Person{
    private:
    int hour;
    long money;
    
    public:
    EmployeePT(){}
    EmployeePT(string name, int age, string add, string tel, string sex, int hour, long money): Person(name, age, add, tel, sex), hour(hour), money(money){}
    int getHour(){
        return hour;
    }
    long getMoney(){
        return money;
    }
    void display(){
        cout << "Employee Part Time" << endl;
        Person::display();
        cout << "Hour: " << hour << endl;
        cout << "Money: " << money << endl;
        cout << "Salary: " << salary() << endl;
    }
    long salary(){
        return money * hour;
    }
    vector<EmployeePT> getMaxSalary(vector<EmployeePT> pt){
        double max = 0;
        vector<EmployeePT> v;
        for(int i = 0; i < pt.size(); i++){
            if( max < pt[i].salary()){
                max = pt[i].salary();
            }
        }
        for (int i = 0; i <pt.size(); i++){
            if (max == pt[i].salary()){
                v.push_back(pt[i]);
            }
        }
        return v;
    }
};


class EmployeeFT : public Person{
    private:
    int day;
    long money;
    
    public:
    EmployeeFT(){}
    EmployeeFT(string name, int age, string add, string tel, string sex, int day, long money): Person(name, age, add, tel, sex){
        this->day = day;
        this->money = money;
    }
    int getDay(){
        return day;
    }
    long getMoney(){
        return money;
    }
    void display(){
        cout <<"Employee Full Time" << endl;
        Person::display();
        cout << "Day: " << day << endl;
        cout << "Money: " << money << endl;
        cout << "Salary: " << salary() << endl;
    }
    long salary(){
        return money*day;
    }
    vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> ft){
        double max = 0;
        vector<EmployeeFT> v;
        for(int i = 0; i < ft.size(); i++){
            if( max < ft[i].salary()){
                max = ft[i].salary();
            }
        }
        for (int i = 0; i <ft.size(); i++){
            if (max == ft[i].salary()){
                v.push_back(ft[i]);
            }
        }
        return v;
    }
};

int main(){
    cout << "aa" ;
    return 0;
}