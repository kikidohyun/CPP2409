#include <iostream>
#include <string>
using namespace std;
#include <vector>

class User
{

protected:
	int hp=20;
	int itemCnt = 0;

public:
	// 유저의 위치를 저장할 변수
	int user_x = 0;
	int user_y = 0;
	User() : hp(20), itemCnt(0) {}
	virtual bool checkXY(User *user_A, int mapX, int mapY) = 0;
	virtual bool checkGoal(User *user_A, vector<vector<int>> &map) = 0;
	virtual void checkState(User *user_A, vector<vector<int>> &map) = 0;
	virtual void DecreaseHP(int dec_hp) = 0;
	virtual void IncreaseHP(int inc_hp) = 0;
	virtual int GetHP() = 0;
	virtual bool CheckUser(User *user) = 0;
	friend ostream &operator<<(ostream &os, const User *v)
	{

		os << "현재 HP는 {" << v->hp << "}이고, 먹은 아이템은 총 {" << v->itemCnt << "}개 입니다" << endl;
		return os;
	}
	virtual void DoAttack() = 0;
};

class Magician : public User
{
public:
	Magician() {}
	void DoAttack()
	{
		cout << "공격합니다" << endl;
		cout << "마법 사용" << endl;
	}
	bool checkXY(User *user_A, int mapX, int mapY)
	{
		bool checkFlag = false;
		if (user_A->user_x >= 0 && user_A->user_x < mapX && user_A->user_y >= 0 && user_A->user_y < mapY)
		{
			checkFlag = true;
		}
		return checkFlag;
	}
	// 유저의 위치가 목적지인지 체크하는 함수
	bool checkGoal(User *user_A, vector<vector<int>> &map)
	{
		// 목적지 도착하면
		if (map[user_A->user_y][user_A->user_x] == 4)
		{
			return true;
		}
		return false;
	}

	void checkState(User *user_A, vector<vector<int>> &map)
	{
		if (map[user_A->user_y][user_A->user_x] == 1)
		{
			cout << "{아이템}이 있습니다." << endl;
			this->itemCnt+=1;
		}
		else if (map[user_A->user_y][user_A->user_x] == 2)
		{
			cout << "{적}이 있습니다" << endl;
			user_A->DecreaseHP(2);
		}
		else if (map[user_A->user_y][user_A->user_x] == 3)
		{
			cout << "{포션}이 있습니다" << endl;
			user_A->IncreaseHP(2);
		}
	}
	void DecreaseHP(int dec_hp = 1)
	{
		this->hp -= dec_hp;
	}
	void IncreaseHP(int inc_hp = -1)
	{
		this->hp += inc_hp;
	}

	int GetHP()
	{
		return this->hp;
	}

	bool CheckUser(User *User)
	{
		if (this->hp == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

class Warrior : public User
{
public:
	Warrior() {}
	void DoAttack()
	{
		cout << "공격합니다" << endl;
		cout << "베기 사용" << endl;
	}

	bool checkXY(User *user_A, int mapX, int mapY)
	{
		bool checkFlag = false;
		if (user_A->user_x >= 0 && user_A->user_x < mapX && user_A->user_y >= 0 && user_A->user_y < mapY)
		{
			checkFlag = true;
		}
		return checkFlag;
	}
	// 유저의 위치가 목적지인지 체크하는 함수
	bool checkGoal(User *user_A, vector<vector<int>> &map)
	{
		// 목적지 도착하면
		if (map[user_A->user_y][user_A->user_x] == 4)
		{
			return true;
		}
		return false;
	}

	void checkState(User *user_A, vector<vector<int>> &map)
	{
		if (map[user_A->user_y][user_A->user_x] == 1)
		{
			cout << "{아이템}이 있습니다." << endl;
			this->itemCnt+=1;
		}
		else if (map[user_A->user_y][user_A->user_x] == 2)
		{
			cout << "{적}이 있습니다" << endl;
			user_A->DecreaseHP(2);
		}
		else if (map[user_A->user_y][user_A->user_x] == 3)
		{
			cout << "{포션}이 있습니다" << endl;
			user_A->IncreaseHP(2);
		}
	}
	void DecreaseHP(int dec_hp = 1)
	{
		this->hp -= dec_hp;
	}
	void IncreaseHP(int inc_hp = -1)
	{
		this->hp += inc_hp;
	}

	int GetHP()
	{
		return this->hp;
	}

	bool CheckUser(User *User)
	{
		if (this->hp == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};
