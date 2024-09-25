
#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));

    int answer=rand()%100;
    int tries=0;

    int guess;

    while(1){
        cout << "정답을 추측하여 보시오:";
        cin >>guess;
        tries++;
        if(guess==answer){
            cout<<"축하합니다. 시도횟수="<<tries<<endl;
            break;
        }
        else{
            if(guess>answer){
                cout<<"제시한 정수가 높습니다"<<endl;
            }
            else{
                cout<<"제시한 정수가 낮습니다."<<endl;
            }
        }
    }

    
    
    
    return 0;
}