

#include "DHTesp.h"

#define DHTpin 15    //D15 of ESP32 DevKit
#define ledPin 13
#define buzzer 12
#define relay 14
#define blueLight 2

DHTesp dht;

void setup()
{
  
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  
  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);

  // use this instead: 
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
  //dht.setup(DHTpin, DHTesp::DHT22); //for DHT22 Connect DHT sensor to GPIO 17


  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(blueLight, OUTPUT);
}

void loop()
{

float humidity = dht.getHumidity();
float temperature = dht.getTemperature();

  // under heat check
  if(temperature < 35.5){
      digitalWrite(buzzer, HIGH);
      delay(70);
      digitalWrite(buzzer, LOW);
  }
  // in normal situation
  if(temperature> 35.5 && temperature < 38.5 ){
      digitalWrite(blueLight, HIGH);
  }else{
    digitalWrite(blueLight, LOW);
  }


  // over heat check
  if(temperature > 38.5){
    digitalWrite(ledPin, HIGH);  // turn off the LED
    digitalWrite(buzzer, HIGH);
    digitalWrite(relay, LOW);
  }else{
    digitalWrite(ledPin, LOW);  // turn off the LED
    digitalWrite(buzzer, LOW);
    digitalWrite(relay, HIGH);
  }
  delay(1000);
  digitalWrite (ledPin, LOW);
  delay(500);

  

  
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity,1);
  Serial.print("H\t\t");
  Serial.print(temperature, 1);
  Serial.print("C\t\t");
  Serial.print(dht.toFahrenheit(temperature), 1);
  Serial.print("\t\t");
  Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
  Serial.print("\t\t");
  Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
}











////////// re usable functions OLED
