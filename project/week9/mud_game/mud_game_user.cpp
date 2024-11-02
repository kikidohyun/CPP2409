#include <iostream>
#include <string>
#include "mud_game.h"
using namespace std;

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool user::checkXY(user &user_A,int mapX, int mapY){
    bool checkFlag = false;
	if (user_A.user_x >= 0 && user_A.user_x < mapX && user_A.user_y >= 0 && user_A.user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}
// 유저의 위치가 목적지인지 체크하는 함수
bool user::checkGoal(user &user_A,int map[][mapX]){
    // 목적지 도착하면
	if (map[user_A.user_y][user_A.user_x] == 4) {
		return true;
	}
	return false;
}

void user::checkState(user &user_A,int map[][mapX]){
	if(map[user_A.user_y][user_A.user_x]==1){
		cout << "{아이템}이 있습니다."<<endl;
	}
	else if(map[user_A.user_y][user_A.user_x]==2){
		cout << "{적}이 있습니다"<<endl;
		user_A.user_hp-=2;
	}
	else if(map[user_A.user_y][user_A.user_x]==3){
		cout << "{포션}이 있습니다"<<endl;
		user_A.user_hp+=2;
	}
}