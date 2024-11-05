#include <iostream>
#include <string>
using namespace std;


class User
{

private:
	int hp;

public:
	// 유저의 위치를 저장할 변수
	int user_x=0;
	int user_y=0;
    bool checkXY(User &user_A, int mapX, int mapY);
    bool checkGoal(User &user_A, int map[][5]);
    void checkState(User &user_A, int map[][5]);
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	User();
	bool CheckUser(User user);
};