
#include <iostream>
using namespace std;

int main(){
    
    int a,b,c,largest;

    cout<<"3개의 정수를 입력하시오: ";

    cin>>a >>b >>c;

    // -2,147,483,648 ~ 2,147,483,647  인트 범위를 넘어가면 프로그램이 종료되는 것을 막고 싶었는데 못막음

   

    if(a>=b&&a>=c)
        largest=a;
    else if (b>=a &&b>=c)
        largest=b;
    else                             // 같은 숫자가 들어갈 수 있으니 등호를 넣음
        largest=c;
    
    cout << "가장 큰 정수는" << largest<<endl;
    return 0;
}