#include <iostream>
#include <string>
using namespace std;
#include "user.h"
#include <vector>
#include <fstream>

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
void displayMap(User *user_A,vector<vector<int>> &map,int job);
void game_excution(User *user_A,vector<vector<int>> &map,int num,int job);
void out_board(User *user_A, int plus_x,int plus_y);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map; 
	ifstream is{"map.txt"};
	if(!is)
	{
		cerr<<"파일 오픈에 실패하셨습니다."<<endl;
		exit(1);
	}
	for(int i=0;i<5;i++)
	{
		vector<int> row;
		for(int j=0;j<5;j++)
		{	int num;
			is>>num;
			row.push_back(num);
		}
		map.push_back(row);
	}
	is.close();


	User* user_A;
	int job;
	// 게임 시작
	
	while(1){
	cout<<"Magicia을 플레이 하고싶다면 1을 Warrior를 플레이 하고싶다면 2를 입력하시오"<<endl;
	cin>>job;
	if(job==1){
		user_A=new Magician();
		break;
	}
	else if(job==2){
		user_A=new Warrior();
		break;
	}
	else{
		cout<<"잘못 입력하셨습니다."<<endl;
	}
	}
	while (1)
	{ // 사용자에게 계속 입력받기 위해 무한 루프
		string user_input = ""; // 사용자의 입력을 저장할 변수

		
			cout << "현재  HP는 " << user_A->GetHP() << "입니다." << endl;
			cout << "명령어를 입력하세요 (up,down,left,right,map,end,information): ";
			cin >> user_input;	
		try{
			if (user_input == "up")
			{
				// 위로 한 칸 올라가기
				game_excution(user_A, map, 8,job);
			}
			else if (user_input == "down")
			{
				// TODO: 아래로 한 칸 내려가기
				game_excution(user_A,map, 2,job);
			}
			else if (user_input == "left")
			{
				// TODO: 왼쪽으로 이동하기
				game_excution(user_A, map, 4,job);
			}
			else if (user_input == "right")
			{
				// TODO: 오른쪽으로 이동하기
				game_excution(user_A, map, 6,job);
			}
			else if (user_input == "map")
			{
				// TODO: 지도 보여주기 함수 호출
				displayMap(user_A, map,job);
			}
			else if (user_input == "end")
			{
				cout << "종료합니다.";
				break;
			}
			else if (user_input == "information")
			{
				cout << user_A ;
			}
			else
			{
				throw runtime_error("잘못된 입력입니다.");
				continue;
			}
		}
		catch(runtime_error& e)
		{
			cout<<"에러: "<<e.what();
		}
			if (!user_A->CheckUser(user_A))
			{
				cout << "실패";
				break;
			}

			// 목적지에 도달했는지 체크
			bool finish = user_A->checkGoal(user_A, map);
			if (finish == true)
			{
				cout << "목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		
		
		

		}
		
		
	delete user_A;
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(User *user_A,vector<vector<int>> &map,int job) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_A->user_y && j == user_A->user_x) {
				if(job==1){
					cout<<"     Magician      |";
				}
				else{
					cout << "      Warrior      |"; // 양 옆 1칸 공백 총 10칸
				}
				
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "                   |"; // 6칸 공백
					break;
				case 1:
					cout << "      아이템       |";
					break;
				case 2:
					cout << "         적        |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << "        포션       |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "       목적지      |";
					break;
				}
			}
		}
		cout << endl;
		cout << " ---------------------------------------------------------------------------------------------------" << endl;
	}
}

void game_excution(User *user_A, vector<vector<int>> &map, int num,int job)
{
		if (num == 8)
		{
			user_A->user_y -= 1;
			user_A->DecreaseHP(1);
			bool inMap = user_A->checkXY(user_A, mapX, mapY);
			if (inMap == false)
			{
				out_board(user_A, 0, 1);
			}
			else
			{
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(user_A, map,job);
				user_A->checkState(user_A, map);
			}
		}
		else if (num == 2)
		{
			user_A->user_y += 1;
			user_A->DecreaseHP(1);
			bool inMap = user_A->checkXY(user_A, mapX, mapY);
			if (inMap == false)
			{
				out_board(user_A, 0, -1);
			}
			else
			{
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(user_A, map,job);
				user_A->checkState(user_A, map);
			}
		}
		else if (num == 4)
		{
			user_A->user_x -= 1;
			user_A->DecreaseHP(1);
			bool inMap = user_A->checkXY(user_A, mapX, mapY);
			if (inMap == false)
			{
				out_board(user_A, 1, 0);
			}
			else
			{
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(user_A, map,job);
				user_A->checkState(user_A, map);
			}
		}
		else if (num == 6)
		{
			user_A->user_x += 1;
			user_A->DecreaseHP(1);
			bool inMap = user_A->checkXY(user_A, mapX, mapY);
			if (inMap == false)
			{
				out_board(user_A, -1, 0);
			}
			else
			{
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(user_A, map,job);
				user_A->checkState(user_A, map);
			}
		}
}
void out_board(User *user_A, int plus_x,int plus_y){
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
	user_A->user_y += plus_y;
	user_A->user_x += plus_x;
	user_A->IncreaseHP(1);

}