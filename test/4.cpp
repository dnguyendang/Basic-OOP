

#include<iostream>
#include<vector>

using namespace std;

class Score{
    protected:
    double math;
    double literature;
    double english;
    
    public:
    Score(){}
    Score(double math, double literature, double english) : math(math), literature(literature), english(english){}
    
    double getMath(){
        return math;
    }
    double getLiterature(){
        return literature;
    }
    double getEnghlish(){
        return english;
    }
    void setMath(double math){
        this->math= math;
    }
    void setLiterature(double literature){
        this->literature = literature;
    }
    void setEnglish(double english){
        this->english = english;
    }
    
    virtual double pointA(){
        return 0;
    }
    virtual double pointB(){
        return 0;
    }
    virtual double pointC(){
        return 0;
    }
    virtual double pointD(){
        return math + literature+ english;
    }
    virtual double avgPoint() = 0;
    
    static double getMaxAvg(vector<Score*> vt){
        double max = 0;
        for (int i = 0; i < vt.size(); i ++){
            if (vt[i]->avgPoint() > max){
                max = vt[i]->avgPoint();
            }
        }
        return max;      
    }
    static double getMinAvg(vector<Score*> vt){
        double min = vt[0]->avgPoint();
        for (int i = 1; i < vt.size(); i ++){
            if (vt[i]->avgPoint() < min){
                min = vt[i]->avgPoint();
            }
        }
        return min;
    }
    bool isPass(){
        return avgPoint()>5?1:0;
    }
    static double getMaxPointA(vector<Score*> vt){
        double max = 0;
        for (int i = 0; i < vt.size(); i ++){
            if (vt[i]->pointA() > max){
                max = vt[i]->pointA();
            }
        }
        return max;   
    }
    static double getMaxPointB(vector<Score*> vt){
        double max = 0;
        for (int i = 0; i < vt.size(); i ++){
            if (vt[i]->pointB() > max){
                max = vt[i]->pointB();
            }
        }
        return max;   
    }
    static double getMaxPointC(vector<Score*> vt){
        double max = 0;
        for (int i = 0; i < vt.size(); i ++){
            if (vt[i]->pointC() > max){
                max = vt[i]->pointC();
            }
        }
        return max;   
    }
    static double getMaxPointD(vector<Score*> vt){
        double max = 0;
        for (int i = 0; i < vt.size(); i ++){
            if (vt[i]->pointD() > max){
                max = vt[i]->pointD();
            }
        }
        return max;   
    }
};


class ScoreNatural : public Score{
    private:
    double physic;
    double chemistry;
    double biology;
    
    public:
    ScoreNatural(){}
    ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology): Score(math, literature, english), physic(physic), chemistry(chemistry), biology(biology){
        // this->physic=physic;
        // this->chemistry=chemistry;
        // this->biology=biology;
    }
    double getPhysic(){
        return physic;
    }
    double getChemistry(){
        return chemistry;
    }
    double getBiology(){
        return biology;
    }
    void setPhysic(double physic){
        this->physic = physic;
    }
    void setChemistry(double chemistry){
        this->chemistry = chemistry;
    }
    void setBiology(double biology){
        this->biology = biology;
    }
    
    double pointA(){
        return math + physic + chemistry;
    }
    double pointB(){
        return math + chemistry + biology;
    }
    double pointNatural(){
        return physic + chemistry + biology; 
    }
    double avgPoint(){
        return (math + literature + english + physic + chemistry + biology)/6;
    }
};


class ScoreSocial : public Score{
    private:
    double ce;
    double geography;
    double history;
    
    public:
    ScoreSocial(){}
    ScoreSocial(double math, double literature, double english, double ce, double geography, double history) : Score(math, literature, english){
        this->ce = ce;
        this->geography = geography;
        this->history = history;
    }
    double getCe(){
        return ce;
    }
    double getGeography(){
        return geography;
    }
    double getHistory(){
        return history;
    }
    void setCe(double ce){
        this->ce = ce;
    }
    void setGeography(double geography){
        this->geography = geography;
    }
    void setHistory(double history){
        this->history = history;
    }
    
    double pointC(){
        return literature + history + geography;
    }
    double pointSocial(){
        return ce + geography + history; 
    }
    double avgPoint(){
        return (math + literature + english + ce + geography + history)/6;
    }
};

int main(){
    Score *p[6];
    p[0] = new ScoreNatural(9,9,9,9,9,9); 
    p[1] = new ScoreNatural(9,9,9,9,9,9); 
    p[2] = new ScoreNatural(8,8,8,8,8,8); 
    p[3] = new ScoreSocial(9,9,9,9,9,9); 
    p[4] = new ScoreSocial(9,9,9,9,9,9); 
    p[5] = new ScoreSocial(8,8,8,8,8,8);
    vector<Score *> vt;
    vt.push_back(p[0]);
    vt.push_back(p[1]);
    vt.push_back(p[2]);
    vt.push_back(p[3]);
    vt.push_back(p[4]);
    vt.push_back(p[5]);
    cout<<Score::getMinAvg(vt);
    return 0;
}