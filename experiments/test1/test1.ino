#define VER "0.0.1"
int temperaturePin = 4;

// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <MKRGSM.h>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // For debugging purpose:
  Serial.begin(9600);

  //Initialize LCD:
  lcd.begin(16,2);

  lcd.setBacklight(TEAL);
  
  //Welcome Message 
  lcd.print("ArdIoT v");
  lcd.print(VER);
  
  delay(1000);
  
  lcd.setCursor(0,1);
  lcd.print("GSM Init...");

  /*Serial.println ("START gsmScan");
  GSMScanner gsmScan = GSMScanner();
  int ret = gsmScan.begin();
  Serial.print("gsmScan.Init return : ");
  Serial.println(ret);
  String networks = gsmScan.readNetworks();
  Serial.println("Networks:");
  Serial.println(networks);*/

  Serial.println("END Setup");
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Time : ");
  lcd.print(millis()/1000);

  lcd.setCursor(0,1);
  lcd.print("Temp : ");
  lcd.print(getTemp());
  delay(1000);
}


float getTemp() {
  float readVal = analogRead(temperaturePin);
  Serial.println();
  Serial.print("analogRead : ");
  Serial.println(readVal);
  float voltage = readVal * 3.3 / 1024;
  Serial.print("Voltage : ");
  Serial.println(voltage);
  float temperature = (voltage - 0.5) * 100;
  Serial.print("Temperature :");
  Serial.println(temperature);
  return temperature;
}
