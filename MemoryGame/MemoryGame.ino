
#include<LiquidCrystal.h>                //LCD를 프로그래밍을 하기 위한 헤더
#include"variable.h"                       //전역변수 모아놓은 헤더

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   //LCD 핀 설정

#include"LCD.h"                            //LCD 출력 함수

void setup()
{
  randomSeed(analogRead(0));              //랜덤 시드 초기화
  
  short i;
  for(i=0;i<4;i++){                       //Button 4개, LED 4개
    pinMode(ButtonSetup[i],INPUT);        //Button 핀 설정
    pinMode(LedSetup[i],OUTPUT);          //LED 핀 설정
  }
  lcd.begin(16,2);                        //LCD 초기 설정
  lcd.setCursor(0,0);                     //LCD (커서)위치 설정
  delay(900);                             //Delay 0.9s
  lcd.clear();                            //LCD 화면 지우기
}

void loop()
{
  int n_array[n_levels];                  
  int u_array[n_levels];

  int i;

  //n_array와 u_array가 일치한다면 새 게임을 시작합니다.
  if (game_on == 0) {                               //만약 
    for (i = 0; i < n_levels; i = i + 1) {          //설정한 level만큼 반복
      n_array[i] = 0;                               //0으로 초기화
      u_array[i] = 0;
      rand_num = random(1, 200);                    //1부터 200까지의 난수 생성
      if (rand_num <= 50)                           //0보다 크고 50보다 작거나 같을 때 (Case) 0
        rando = 0; 
      else if (rand_num > 50 && rand_num <= 100)    //50보다 크고 100보다 작을 때 (Case) 1
        rando = 1; 
      else if (rand_num > 100 && rand_num <= 150)   //100보다 크고 150보다 작을 때 (Case) 2
        rando = 2;
      else if (rand_num <= 200)                     //150보다 크고 200보다 작을 때 (Case) 3
        rando = 3;

      n_array[i] = rando;                           //랜덤값 저장
      
    }

    game_on = 1;                    //게임 시작
    delay(3000);                    //1초 대기
    GameStart();                    //Show Game Start
    delay(2000);                    //0.5초 대기
  }
  GameLevel(currentlevel);          //Show Game Level

  if (wait == 0) {                  //wait값이 0이라면
    delay (200);                    //0.2초 대기
    i = 0;
    for (i = 0; i < currentlevel; i = i + 1) {   //현재 레벨(currentlevel)만큼 반복
      leddelay = 1.5 * ledtime / (1 + (speedfactor / n_levels) * (currentlevel - 1)); //
      pinandtone = n_array[i];                                                  //난수(랜덤값) 저장
      digitalWrite(pinandtone + 6, HIGH);                                       //LED ON
      delay(leddelay * 1.2);                                                          //
      digitalWrite(pinandtone + 6, LOW);                                        //LED OFF
      delay(100 / speedfactor);                                                 //
    }
    wait = 1;                               //wait 1
  }
  i = 0;
  int buttonchange = 0;
  int j = 0; 
  while (j < currentlevel) {                //j가 현재 레벨보다 작을 때까지 반복
    while (buttonchange == 0) {             //button
      for (i = 0; i < 4; i = i + 1) {       //4번 반복
        buttonState[i] = digitalRead(ButtonSetup[i]);   //현재 버튼의 상태를 buttonState의 상태에 저장
        buttonchange = buttonchange + buttonState[i];
      }
    }
    for (i = 0; i < 4; i = i + 1) {   //4번 반복
      if (buttonState[i] == HIGH) {   //i번째의 버튼이 눌렸다면
        digitalWrite(i + 6, HIGH);    //
        delay(ledtime * 1.2);         //
        digitalWrite(i + 6, LOW);     //
        wait = 0;                     //
        u_array[j] = i;               //j단계에선 i번째 LED가 켜졌다는 것을 저장
        buttonState[i] = LOW;         //버튼 초기화
        buttonchange = 0;             //
      }
    }

    if (u_array[j] == n_array[j]) {   //버튼을 정확이 눌렀다면
      j++;                            //
      right = 1;                      //
    }
    else {                            //Game Over
      right = 0;
      i = 4;
      j = currentlevel;
      wait = 0;
    }
  }

  if (right == 0) {                    //Game Over
    lcd.noDisplay();
    delay(400);
    lcd.display();
    delay(400);
    lcd.noDisplay();  
    delay(400);
    lcd.display();
    delay(400);
    
    delay(300);
    i = 0;
    game_on = 0;
    currentlevel = 1;
     
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 6, HIGH);
    }
    delay(ledtime);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 6, LOW);
    }
    
    delay (200);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 6, HIGH);
    }
    delay(ledtime);
    for (i = 0; i < 4; i = i + 1) {
      digitalWrite(i + 6, LOW);
    }
    
    lcd.clear();
    //
    GameOver();
    delay(2000);  
    //
    delay(500);
    game_on = 0;
  }
  
  if (right == 1) {          //currentlevel success
    currentlevel++;
    wait = 0;
  }

  //게임 클리어
  if (currentlevel == n_levels) {
    delay(300);
    GameClear();
    
    //게임 재시작을 위한 변수 설정
    game_on = 0;
    currentlevel = 1;
    n_levels = n_levels + 2;
    speedfactor = speedfactor + 1;
  }
}

