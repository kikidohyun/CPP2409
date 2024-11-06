#include <iostream>
#include <vector>
using namespace std;

class movie{
private:
    string name;
    int score;
public:
    movie(string n, int s){
        name=n;
        score=s;
    }
    void Print(){
        cout<<name<<": "<<score<<endl;
    }
};

int main(void){
    vector<movie> v;
    v.push_back(movie("Inside Out",10));
    v.push_back(movie("Zootopia",9));
    v.push_back(movie("Coco",8));

    for(auto i:v){
        i.Print();
    }
}