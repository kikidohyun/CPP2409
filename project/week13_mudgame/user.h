#include <iostream>
#include <string>
using namespace std;
#include <vector>


class User
{

private:
	int hp;
	int itemCnt=0;

public:
	// 유저의 위치를 저장할 변수
	int user_x=0;
	int user_y=0;
    bool checkXY(User &user_A, int mapX, int mapY);
    bool checkGoal(User &user_A, vector<vector<int>> &map);
    void checkState(User &user_A, vector<vector<int>> &map);
	void DecreaseHP(int dec_hp);
	void IncreaseHP(int inc_hp);
	int GetHP();
	User();
	bool CheckUser(User& user);
	friend ostream& operator<<(ostream& os, const User& v){
		
		os << "현재 HP는 {" << v.hp<< "}이고, 먹은 아이템은 총 {"<<v.itemCnt<<"}개 입니다"<< endl;
		return os;
	}
	virtual void DoAttack()=0;

};

class Magician : public User
{
public:
	void DoAttack()
	{
		cout<<"공격합니다"<<endl;
		cout << "마법 사용" << endl;
	}
};

class Warrior : public User
{
public:
	void DoAttack()
	{
		cout<<"공격합니다"<<endl;
		cout << "베기 사용" << endl;
	}
};
