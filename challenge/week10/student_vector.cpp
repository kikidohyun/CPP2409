#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int sum=0;
    int count=0;
    int avg;
    
    for(int i=0;i>-1;i++){
    cout<<"성적을 입력하시오(종료는 -1) : ";
    int x;
    cin>>x;
    if(x==-1){
        break;
     }
    else{
        v.push_back(x);
     }
    }
    for(int i:v){
        sum+=i;
        count++;
    }

    avg=sum/count;
    cout<<"성적 평균="<<avg;
}