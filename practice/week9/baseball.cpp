
 #include <iostream>
#include <string>
using namespace std;

bool checkNumber(int first, int second, int third){
    if(first!=second&&first!=third&&second!=third){
        return true;
    }
    else return false;
}

int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum; // ������ ù��° �ڸ���
	int secondNum; // ������ �ι�° �ڸ���
	int thirdNum; // ������ ����° �ڸ���
    int first;
	int sec;
	int th;

		
	th=randomNum%10;
	first=randomNum/100;
	sec=(randomNum-first*100)/10;

	while (1) {		
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same;  // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		
		
		same= checkNumber(first, sec, th);
		
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << " try " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "enter the three number ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			guessThird=userNumber%10;
	 		guessFirst=userNumber/100; 
			guessSecond=(userNumber-(guessFirst*100))/10; 
            if (to_string(userNumber).length() != 3) {
				if(userNumber/10==0){
                    guessFirst=0;
                    guessSecond=0;

				}
				else if(userNumber/100==0){
					guessFirst=0;
					guessThird=userNumber%10;
					guessSecond=userNumber/10; 

				}
				else{
					cout << "not three number , enter again" << endl;
					continue;
				}
				
			}

			same= checkNumber(guessFirst, guessSecond, guessThird);
		


			if (same == true) {
				break;
			}
			cout<<"yournumber have same number "<<endl;
		}
		
		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����
		
		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		int num[3];
		num[0]=first;
		num[1]=sec;
		num[2]=th;

		
		int user[3];
		user[0]=guessFirst;
		user[1]=guessSecond;
		user[2]=guessThird;

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(user[i]==num[j]){
					if(i==j){
						strike++;
						break;
					}
					else{
						ball++;
                        break;
					}
				}
			}
		}
		

		cout << guessFirst<<guessSecond<<guessThird << "'s result : " << strike << " strike, " << ball << "ball " << endl;
		
		if (strike == 3) {
			cout << "correct number, end game";
			break;
		}

		turn += 1;
	}

	return 0;
}
           