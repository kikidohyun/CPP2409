#include <iostream>
#include <string>
#include "user.h"
using namespace std;
#include <vector>

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool User::checkXY(User &user_A,int mapX, int mapY){
    bool checkFlag = false;
	if (user_A.user_x >= 0 && user_A.user_x < mapX && user_A.user_y >= 0 && user_A.user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}
// 유저의 위치가 목적지인지 체크하는 함수
bool User::checkGoal(User &user_A,vector<vector<int>> &map){
    // 목적지 도착하면
	if (map[user_A.user_y][user_A.user_x] == 4) {
		return true;
	}
	return false;
}

void User::checkState(User &user_A,vector<vector<int>> &map){
	if(map[user_A.user_y][user_A.user_x]==1){
		cout << "{아이템}이 있습니다."<<endl;
	}
	else if(map[user_A.user_y][user_A.user_x]==2){
		cout << "{적}이 있습니다"<<endl;
		user_A.DecreaseHP(2);
	}
	else if(map[user_A.user_y][user_A.user_x]==3){
		cout << "{포션}이 있습니다"<<endl;
		user_A.IncreaseHP(2);
	}
}
void User:: DecreaseHP(int dec_hp=1){
	hp-=dec_hp;
}
void User:: IncreaseHP(int inc_hp=-1){
	hp+=inc_hp;
}

int User:: GetHP(){
	return hp;
}

User:: User(){
	hp=20;
}

bool User::CheckUser(User User){
	if(User.hp==0){
		return false;
	}
	else{
		return true;
	}
}