
#include <iostream>
using namespace std;

int main(){
    const int numCell=3;
    char board[numCell][numCell]{};
    int x,y; // 사용자에게 입력받는 x,y좌표

    //보드판 초기화

    for(x=0;x<numCell;x++){
        for(y=0;y<numCell;y++){
            board[x][y]=' ';
        }
    }

    //게임하는 코드

    int k=0; //누구 차례인지 체크하기 위한 변수
    char currentUser='X'; //현재 유저의 돌을 저장하기 위한 변수
    int boo=1; // 무한 루프의 조건 < -- 승리 조건 만족시 while문을 빠져나오기 위해 설정

    while(boo){
    //1. 누구 차례인지 출력
    switch(k%2){
        case 0:
            cout<<"첫번째 유저(x)의 차례입니다 ->";
            currentUser='X';
            break;
        case 1:"두번째 유저(0)의 차례입니다->";
            currentUser='O';
            break;
    }

    //2. 좌표 입력받기

    cout <<"(x,y)좌표를 입력하세요: ";
    cin >>x >>y;

    //3. 입력받은 좌표의 유효성 체크

    if(x>=numCell||y>=numCell){
        cout<<x<<", "<<y<<", ";
        cout<<"x와 y 둘 중 하나가 칸을 벗어납니다."<<endl;
        continue;
    }
    if(board[x][y]!=' '){
        cout<<x<<", "<<y<<": 이미 돌이 차있습니다."<<endl;
        continue;
    }

    //4.입력받은 좌표에 현재 유저의 돌 놓기
    board[x][y]=currentUser;

    //5.현재 보드판 출력
    for(int i=0;i<numCell;i++){
        cout<<"---|---|---"<<endl;
        for(int j=0;j<numCell;j++){
            cout<<board[i][j];
            if(j==numCell-1){
                break;
            }
            cout<<"  |";
        }
        cout<<endl;

    }
    cout<<"---|---|---"<<endl;
    k++;
  //6.빙고시 승자 출력
  //6-1. 가로 빙고 성공
    for(int i=0;i<numCell;i++){
        if(board[i][0]!=' '&&board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
            if(board[i][0]=='X'){
                cout<<"유저(x)가 승리하셨습니다"<<endl;
                boo=0;
                break;
            }
            else if(board[i][0]=='O'){
                cout<<"유저(o)가 승리하셨습니다."<<endl;
                  boo=0;
                break;
            }
        }
    }

  //6-2 세로 빙고 성공
  for(int i=0;i<numCell;i++){
        if(board[0][i]!=' '&&board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
            if(board[0][i]=='X'){
                cout<<"유저(x)가 승리하셨습니다"<<endl;
                  boo=0;
                break;
            }
            else if(board[0][i]=='O'){
                cout<<"유저(o)가 승리하셨습니다."<<endl;
                  boo=0;
                break;
            }
        }
  }
  //6-3 대각선 빙고 성공

    if((board[0][0]!=' '&&board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[0][0]!=' '&&board[0][2]==board[1][1]&&board[1][1]==board[2][0])){
        if(board[1][1]=='X'){
                cout<<"유저(x)가 승리하셨습니다"<<endl;
                  boo=0;
                break;
            }
            else if(board[1][1]=='O'){
                cout<<"유저(o)가 승리하셨습니다."<<endl;
                  boo=0;
                break;
            }
    }
// 7.모든 칸이 찼으면 종료
    int check =0; // 빈칸이 하나라도 있으면 1
    for(x=0;x<numCell;x++){
        for(y=0;y<numCell;y++){
           if (board[x][y]==' '){
            check=1;
           }
           
        }
    }
    // 빈칸이 없어 check 값이 0이 나오면 종료
    if(check==0){
        cout<<"모든 칸이 찼으므로 게임을 종료하겠습니다."<<endl;
        boo=0;
    }


    

    }


    return 0;

}