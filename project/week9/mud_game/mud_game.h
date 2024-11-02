#include <iostream>
#include <string>
using namespace std;


class user
{

 static const int mapX = 5;
 static const int mapY = 5;

public:
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	int user_hp = 20;
    bool checkXY(user &user_A, int mapX, int mapY);
    bool checkGoal(user &user_A, int map[][mapX]);
    void checkState(user &user_A, int map[][mapX]);
};
