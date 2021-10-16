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
    People(string name, int age, string job, string id):name(name), age(age), job(job), id(id){}
    
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

class Family{
    private:
    string nameF;
    string status;
    string add;
    vector<People> p;
    
    public:
    Family(){
        nameF = p[0].getName();
    }
    Family(string add, string status, vector<People> p):status(status), add(add), p(p){
        nameF = p[0].getName();
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
        cout << "household's name: " << nameF << endl;
        cout << "Number Member: " << p.size() << endl;
        cout << "Addess: " << add << endl;
        cout << "Status: " << status << endl;
        cout << "List Information Member " << endl;
        for(int i = 0; i < p.size(); i++ ){
            p[i].display();
        }
    }
    
	static vector<Family> getPoorHousehold(vector<Family>fa)
	{
		vector<Family> v;
		for (int i = 0; i < fa.size(); i++)
		{
			if (fa[i].getStatus() == "poor")
			{
				v.push_back(fa[i]);
			}
		}
		return v;
	}
	
    static vector<Family> findFamilySurename(vector<Family> fa, string surename){
        vector<Family> vt;
        for(int i = 0; i <fa.size();i++){
            if(fa[i].getNameF() == surename){
                vt.push_back(fa[i]);
            }
        }
        return vt;
    }
};

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
        double sum = 0;
        int n = 0;
        vector<Family> F(v.getF());
        for(int i = 0 ; i < F.size();i++){
            vector<People> P (F[i].getP());
            for(int j = 0 ; j < P.size(); j++){
                sum += P[j].getAge();
            }
            n += P.size();
        }
        return sum/n;
    }
    static vector<People> getPeopleHaveNotJob(Group g){
        vector<People> vt;
        vector<Family> F(g.getF());
        for(int i = 0 ; i < F.size();i++){
            vector<People> P (F[i].getP());
            for(int j = 0 ; j < P.size(); j++){
                if(P[j].getJob() == ""){
                    vt.push_back(P[j]);
                }
            }
        }
        return vt;
    }
};
