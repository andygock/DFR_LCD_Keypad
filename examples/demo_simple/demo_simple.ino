// Demo of a Keypad LCD Shield
// Common design sold by DFRobot, various vendors on eBay etc

#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>

// this is factory config shield initialisation
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// below is for shield which has been modified (author's shield)
// LiquidCrystal lcd(8,3,4,5,6,7);

// initialise the keypad
DFR_LCD_Keypad keypad(A1, &lcd);

int last_key, key;

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Press keys now");
}

void loop()
{
  last_key = keypad.get_last_key();
  key = keypad.read_key();

  // only clear and update the LCD if they key state has changed
  if (key != last_key)
  {
    // key has changed

    lcd.clear();
    lcd.setCursor(0, 0);

    // print the key selection to the LCD
    switch (key)
    {
    case KEY_RIGHT:
      Serial.print("Right\n");
      lcd.print("RIGHT");
      break;

    case KEY_UP:
      Serial.print("Up\n");
      lcd.print("UP");
      break;

    case KEY_DOWN:
      Serial.print("Down\n");
      lcd.print("DOWN");
      break;

    case KEY_LEFT:
      Serial.print("Left\n");
      lcd.print("LEFT");
      break;

    case KEY_SELECT:
      Serial.print("Select\n");
      lcd.print("SELECT");
      break;

    case KEY_NONE:
    default:
      lcd.print("NONE");
      break;
    }
  }

  delay(20); // optional, but recommended if you are not debouncing the keys
}
