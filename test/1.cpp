#include<iostream>
#include<vector>
using namespace std;

class Student{
    private:
    string name;
    double math;
    double physic;
    double chemistry;
    
    public:
    Student(){}
    Student(string name, double math, double physic, double chemistry){
        this->name = name;
        this->math = math;
        this->physic = physic;
        this->chemistry = chemistry;
    }
    double getMath(){
        return math;
    }
    double getPhysic(){
        return physic;
    }
    double getChemistry(){
        return chemistry;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Point math: " << math << endl;
        cout << "Point physic: " << physic << endl;
        cout << "Point chemistry: " << chemistry << endl;
        cout << "Average: " << avgPoint() << endl;
    }
    double avgPoint(){
        return (math+physic+chemistry)/3;
    }
    static vector<Student> getStudentMaxAvg(vector<Student> vt){
        vector<Student> avg;
        double max = 0;
        for(int i = 0; i < vt.size(); i++){
            if(max < vt[i].avgPoint()){
                max = vt[i].avgPoint();
            }
        }
        for (int i = 0; i < vt.size(); i++){
            if (vt[i].avgPoint() == max){
                avg.push_back(vt[i]);
            }
        }
        return avg;
    }
    
    static vector<Student> getStudentMaxMath(vector<Student> vt){
        vector<Student> math;
        double max = 0;
        for(int i = 0; i < vt.size(); i++){
            if(max < vt[i].getMath() ){
                max = vt[i].getMath();
            }
        }
        for (int i = 0; i < vt.size(); i++){
            if (vt[i].getMath() == max){
                math.push_back(vt[i]);
            }
        }
        return math;
    }
    
    static vector<Student> getStudentMaxPhysic(vector<Student> vt){
        vector<Student> physic;
        double max = 0;
        for(int i = 0; i < vt.size(); i++){
            if(max < vt[i].getPhysic()){
                max = vt[i].getPhysic();
            }
        }
        for (int i = 0; i < vt.size(); i++){
            if (vt[i].getPhysic() == max){
                physic.push_back(vt[i]);
            }
        }
        return physic;
    }
    
    static vector<Student> getStudentMaxChemistry(vector<Student> vt){
        vector<Student> chemistry;
        double max = 0;
        for(int i = 0; i < vt.size(); i++){
            if(max < vt[i].getChemistry()){
                max = vt[i].getChemistry();
            }
        }
        for (int i = 0; i < vt.size(); i++){
            if (vt[i].getChemistry() == max){
                chemistry.push_back(vt[i]);
            }
        }
        return chemistry;
    }
    
};