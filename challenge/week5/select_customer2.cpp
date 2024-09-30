
#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople =5;
    string names[maxPeople];
    int ages[maxPeople];
    int max,min;
    int max_num,min_num;

    cout << maxPeople<<"명의 회원 정보를 입력해주세요."<<endl;

    for(int i=0;i<maxPeople;i++){

        cout <<"사람"<<i+1<<"의 이름: ";
        cin >>names[i];
        cout <<"사람"<<i+1<<"의 나이: ";
        cin >>ages[i];
    }

    max=ages[0];
    for(int i=1;i<maxPeople;i++){
        if(ages[i]>max){
        max=ages[i];
        max_num=i;
        }
    }

    min=ages[0];
    for(int i=1;i<maxPeople;i++){
        if(ages[i]<min){
        min=ages[i];
        min_num=i;
        }
    }

    while(true){
        int choice_num;
        cout<< "1. 가장 나이가 많은 사람 출력"<<endl;
        cout<< "2. 가장 나이가 적은 사람 출력"<<endl;
        cout<< "3.종료"<<endl;
        cin>>choice_num;

        switch(choice_num){
            case 1: 
                cout<<"나이가 가장 많은 사람은 "<<names[max_num]<<"("<<ages[max_num]<<")"<<endl;
                break;
            case 2:
                cout<<"나이가 가장 적은 사람은 "<<names[min_num]<<"("<<ages[min_num]<<")"<<endl;
                break;
            default:
            cout<<"종료"<<endl;
                break;
        }
        cout<<"       {사람 명단}"<<endl;
        for(int i=0;i<maxPeople;i++){
            cout<<names[i]<<"("<<ages[i]<<")"<<endl;

        }
        if(choice_num==3)break;
    }
    
    return 0;
}