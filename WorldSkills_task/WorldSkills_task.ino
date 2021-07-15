#include <LiquidCrystal.h>

// ******************************** variables

boolean wp_state = true;

String wordWorld = "World", wordSkills = "Skills", tempW = "", tempS = "";

int i, j;

// ********************************

LiquidCrystal lcd(13, 12, 8, 7, 6, 5);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  WallPaper();
}

// some shitcode here

void WallPaper() {
  if(wp_state) {
    for (i = 15, j = 0 ; (i >= 7) || (j <= 12); i -= 1 * (i >= 6), j += 1 * (j <= 12)) {
      lcd.clear();
      
      // World
      
      lcd.setCursor(i, 0);
      if(i >= 11)
        tempW += wordWorld[15-i];
      lcd.print(tempW);
      
      // Skills
      
      lcd.setCursor(0, 1);
      if(j <= 6)
        tempS = wordSkills[5-j] + tempS;
      else
        tempS = " " + tempS;
      lcd.print(tempS);
      delay(300);
    }
    while(wp_state)
    	delay(100);
  }
}
