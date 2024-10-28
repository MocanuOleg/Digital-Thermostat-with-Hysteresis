#include <LiquidCrystal.h>
#include <dht11.h>

const int btn = 2, relay = 3, dht = 8;
const int E = 11, RS = 12, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
dht11 DHT11;

bool btnFlag = false;
bool heaterState = false;



void setup() {
  // put your setup code here, to run once:
  pinMode(dht, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(btn, INPUT);
  lcd.begin(16,2);
  //lcd.print("Oleg");

}

void loop() {
  // put your main code here, to run repeatedly:

  
  lcd.setCursor(0, 0);
  int chk = DHT11.read(dht);
  int humidity = (float)DHT11.humidity;
  int temperature = (float)DHT11.temperature;
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Heater is:");
  heaterState?lcd.print("ON "):lcd.print("OFF");
  
  //lcd.print(humidity);
  

  if(temperature > 24){
    digitalWrite(relay, LOW);
  }
  if(temperature < 22){
    digitalWrite(relay, HIGH);
  }

  if(digitalRead(btn) && !btnFlag){
    btnFlag = true;
    heaterState = !heaterState;
  }
   if(!digitalRead(btn) && btnFlag){
    btnFlag = false;
  }

  


}
