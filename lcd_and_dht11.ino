#include <LiquidCrystal.h>
#include <DHT11.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7;
const int dht11Pin = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT11 dht11(dht11Pin);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(4, 0);

  lcd.print("Hi user!");

  int temperature, humidity;
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  lcd.setCursor(0,1);
  
  if (result == 0)
  {
    lcd.print("Temp:");
    lcd.print(temperature);
    lcd.print("C | Wilg:");
    lcd.print(humidity);
    lcd.print("%");
  }
  else
  {
    lcd.print(DHT11::getErrorString(result));
  }

  for (int i = 0; i < 12; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }

  for (int i = 0; i < 12; i++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }
  delay(3000);
  lcd.clear();

}
