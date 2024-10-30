
 #include <iostream>
using namespace std;

class Rectangle{
public:
    int width, height;
    int CalArea(){
            return width*height;
    }
    
};

int main (){
    Rectangle obj;
    Rectangle obj2;
    obj.width=3;
    obj.height=4;
    obj2.height=10;
    obj2.width=10;
    int area2=obj2.CalArea();
    int area=obj.CalArea();
    cout << "사각형의 넓이: " <<area<<endl;
    cout << "사각형2의 넓이: "<<area2<<endl;
    return 0;
}