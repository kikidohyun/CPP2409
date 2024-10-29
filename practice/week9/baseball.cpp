
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
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수
    int first;
	int sec;
	int th;

		
	th=randomNum%10;
	first=randomNum/100;
	sec=(randomNum-first*100)/10;

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same;  // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		
		
		same= checkNumber(first, sec, th);
		
		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << " try " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "enter the three number ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
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
		
		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수
		
		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
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
           