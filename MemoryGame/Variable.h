
#define button1 A2              //첫 번째 button
#define button2 A3              //두 번째 button
#define button3 A4              //세 번째 button
#define button4 A5              //네 번째 button

#define led1 6                  //첫 번째 LED
#define led2 7                  //두 번째 LED
#define led3 8                  //세 번째 LED
#define led4 9                  //네 번쨰 LED

int ButtonSetup[] = {button1, button2, button3, button4};
int LedSetup[] = {led1, led2, led3, led4};
int buttonState[] = {0, 0, 0, 0};
int lastButtonState[] = {0, 0, 0, 0};
int buttonPushCounter[] = {0, 0, 0, 0};

int game_on = 0;        //
int wait = 0;           //
int currentlevel = 1;   //현재 진행 단계의 level
long rand_num = 0;      //random 함수로부터 생성된 난수를 담기 위한 long 형태의 변수
int rando = 0;          //rand_num의 값에 따라 넣으줄 int 형태의 변수(생성된 난수를 바탕으로 킬 ELD를 정해줄 때 사용)
int butwait = 500;      //다음 버튼이 눌러지기까지 대기하는 시간
int ledtime = 500;      //버튼이 눌러졌을 때 LED가 점등해 있는 시간
int n_levels = 30;      //게임의 maximum 단계
int pinandtone = 0;     //생성된 난수에 따라 킬 배열 순서를 담는 변수(n_array의 값)
int speedfactor = 5;    //

  
int leddelay = 200;     //처음 레벨일 때 LED 속도, 레벨이 증가할수록 LED delay 감소
int right = 0;          //다음 레벨로 넘어가는 과정에서 버튼이 제대로 눌렀는지 안눌렀는지를 판단하기 위해 사용할 변수

