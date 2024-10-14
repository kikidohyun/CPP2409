#include <iostream>
#include <string>
using namespace std;


string toLowerStr(string str){
    for(char &c : str){
        c=tolower(c);
    }
    return str;
}

string toUpperStr(string str){
    for(char &c : str){
        c=toupper(c);
    }
    return str;
}

int calcHammingDist(string s1, string s2){
    int count =0;
     if ( s1.length()!= s2.length()){
        
        return -1;}
    else{
        for (int i=0; i <s1.length();i++){
            if(s1[i]!=s2[i]){
            count+=1;}
        }
        return count;
    }
}
int main(){
    
   string s1,s2;
  
   
  
   int count=-1;
   while(count==-1){
    cout << "DNA1: ";
   cin >>s1;
   cout <<"DNA2: ";
   cin >>s2;
    s1=toLowerStr(s1);
   s2=toLowerStr(s2);
    count=calcHammingDist(s1,s2);
   
    if(count==-1){
        
        cout << "문자열의 길이가 다릅니다 다시 입력하세요"<<endl;
    }
   } 
   cout << "해밍 거리는"<<count <<endl;
    return 0;
}