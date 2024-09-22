

#include <iostream>
#include <string>

using namespace std;

int main() {

    int money, candy,cost;

    cout << "현재 가지고 있는 돈:";
    cin >> money;
    cout << "캔디의 가격:";
    cin >> cost;
    candy=money/cost;
    cout <<  "최대로 살 수 있는 캔디=" << candy<<endl;
    cout << "캔디 구입 후 남은 돈="<< money-candy*cost<<endl;


    return 0;
}
