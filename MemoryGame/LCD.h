
//Show GameStart
void GameStart()
{
  lcd.clear();
  lcd.write("Game Start");
}

//Show Gamelevel
void GameLevel(int i)
{
  char num[2] = {0};
  if(i <= 9){
    lcd.clear();
    lcd.write("   Game level   ");
    lcd.setCursor(7,1);
    lcd.print(i);
  }else{
    lcd.clear();
    lcd.write("   Game level");
    lcd.setCursor(7,1);
    num[0] = i / 10 + '0';
    num[1] = i % 10 + '0';
    lcd.write(num);
  }
}

//Show GameOver
void GameOver()
{
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("   GAME OVER");
  //delay(600);
}

//GameClear
void GameClear()
{
  lcd.setCursor(3,0);
  lcd.clear();
  lcd.write("  Game Clear");
  delay(5000);
  lcd.clear();
}

