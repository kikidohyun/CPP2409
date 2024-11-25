#include <iostream>
using namespace std;

class RemoteControl{
public:
    virtual void TurnON()=0;
    virtual void TurnOFF()=0;
};

class Television:public RemoteControl{
public:
    void TurnON(){
        cout<<"TV를 켬"<<endl;
    }
    void TurnOFF(){
        cout<<"TV를 끔"<<endl;
    }
};

class Refrigerator:public RemoteControl{
public:
    void TurnON(){
        cout<<"냉장고를 켬"<<endl;
    }
    void TurnOFF(){
        cout<<"냉장고를 끔"<<endl;
    }
};

int main(){

    RemoteControl* remoteTV= new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    RemoteControl* remoteRefrigerator=new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();
    
    delete remoteTV,remoteRefrigerator;
    return 0;
}