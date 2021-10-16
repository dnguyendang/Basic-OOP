// #pragma once
#include<iostream>
#include<vector>

using namespace std;

class People{
    private:
    string name;
    int age;
    string job;
    string id;
    
    public:
    People(){}
    People(string name, int age, string job, string id){
        this->name = name;
        this->age = age;
        this->job = job;
        this->id = id;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getJob(){
        return job;
    }
    string getId(){
        return id;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Job: " << job << endl;
        cout << "Id: " << id << endl;
    }
};

// #include "People.cpp"

class Family{
    private:
    string nameF;
    string status;
    string add;
    vector<People> p;
    
    public:
    Family(){}
    Family(string nameF, string status, string add, vector<People> p){
        this->nameF = nameF;
        this->status = status;
        this->add = add;
        this->p = p;
    }
    string getNameF(){
        return nameF;
    }
    string getStatus(){
        return status;
    }
    string getAdd(){
        return add;
    }
    vector<People> getP(){
        return p;
    }
    void display(){
        cout << "householder's name: " << nameF << endl;
        cout << "Number Member" << p.size() << endl;
        cout << "Address: " << add << endl;
        cout << "Status: " << status << endl;
        cout << "List Information Member" << endl;
        for(int i = 0; i < p.size(); i++){
            p[i].display();
        }
    }
    static vector<Family> getPoorHousehold(vector<Family> fa){
        vector<Family> vt;
        for (int i = 0; i < fa.size(); i ++){
            if  (fa[i].status == "Poor"){
                vt.push_back(fa[i]);
            }
        }
        return vt;
    }
    static vector<Family> findFamilySurname(vector<Family> fa, string surename){
        vector<Family> vt;
        for(int i = 0; i < fa.size(); i++){
            if (fa[i].nameF == surename){
                vt.push_back(fa[i]);
            }
        }
        return vt;
    }
};

// #include"People.cpp"

class Group{
    private:
    string nameGr;
    vector<Family> f;
    
    public:
    Group(){}
    Group(string nameGr, vector<Family> f): nameGr(nameGr), f(f){}
    string getNameGr(){
        return nameGr;
    }
    vector<Family> getF(){
        return f;
    }
    int getNumberFamily(){
        return f.size();
    }
    static double avgAgeGroup(Group v){
        long sum = 0;
        int n = 0;
        vector<Family> F(v.getF());
        for (int i = 0; i < F.size();i++){
            vector<People> P(F[i].getP());
            for(int j = 0; j < P.size();j++){
                sum += P[j].getAge();
            }
            n += P.size();
        }
        return sum/n;
    }
    static vector<People> getPeopleHaveNotJob(Group g){
        vector<People> vt;
        vector<Family> F(g.getF());
        for(int i = 0; i <F.size();i++){
            vector<People> P (F[i].getP());
            for(int j = 0; j < P.size(); j++){
                if (P[j].getJob() == ""){
                    vt.push_back(P[j]);
                }
            }
        }
        return vt;
    }
};

int main(){
    People x("A", 20, "Dev", "1001");
    People y("B", 21, "Doctor", "1002");
    People z("C", 10, "", "1003");
    People t("D", 30, "Singer", "1004");
    vector<People> p;
    p.push_back(x);
    p.push_back(y);
    p.push_back(z);
    p.push_back(t);
    Family a( "Normal", "Vinh Dien", p);
    People x1("A1", 25, "Dev", "1005");
    People y1("B", 24, "Doctor", "1006");
    People z1("C", 8, "", "1007");
    People t1("D", 35, "Singer", "1008");
    vector<People> p1;
    p1.push_back(x1);
    p1.push_back(y1);
    p1.push_back(z1);
    p1.push_back(t1);
    Family b( "Normal", "Dien An", p1);
    vector<Family> f;
    f.push_back(a);
    f.push_back(b);
    Group gr("Khoi pho 1", f);
    vector<People> people(Group::getPeopleHaveNotJob(gr));
    cout << "Number people don't have job:" << people.size() << endl;
    for (int i = 0; i < people.size(); i++)
    {
        // f.size(): sl các gia đình
        // p.size() hoặc getP().size(): sl các thành viên trong gđ
        people[i].display();// in ra thông tin people not job
        for (int j = 0; j < f.size(); j++)// chạy tới khi quét hết số lượng các gia đình
        {
            vector<People>P( f[j].getP());
            for (int k = 0; k < P.size(); k++)// chạy tới khi quét hết số lượng các thành viên trong gđ đó
            {
                if (P[k].getAge() == people[i].getAge() and P[k].getName() == people[i].getName() and P[k].getId() == people[i].getId())
                {
                    cout << "Con cua chu ho: " << f[j].getNameF()<< endl;
                    cout << "Dia chi cua chu ho: " << f[j].getAdd() << endl;
                    cout << "\n\t ======***=======\t\n";
                }
            }
        }
    }
    return 0;
}