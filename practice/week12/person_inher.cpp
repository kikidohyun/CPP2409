#include <iostream>
using namespace std;
#include <string>

class Person
{
    
protected:
    string address;
    string name;
};


class Student : Person
{
public:
    void SetAddress(string add)
    {
        address = add;
    }
    string GetAddress()
    {
        return address;
    }
    void SetName(string name) { this->name = name; } // 에러
};
int main()
{
    Student obj;
    obj.SetName("미수"); // 에러
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    return 0;
}
