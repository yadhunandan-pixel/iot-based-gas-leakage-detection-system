#include <Ardui̥no.h>
#include <SoftwareSerial.h>

#define MQ2_PIN A0
#define BUZZER_PIN 8
#define LED_PIN 9

SoftwareSerial sim800(10, 11);

int gasThreshold = 400;

void setup() 
{
  Serial.begin(9600);
  sim800.begin(9600);
  pinMode(MQ2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void sendSMS(String message) 
{
  sim800.println("AT+CMGF=1");
  delay(1000);
  sim800.println("AT+CMGS=\"+91XXXXXXXXXX\"");
  delay(1000);
  sim800.print(message);
  delay(1000);
  sim800.write(26);
  delay(5000);
}

void loop() 
{
  int gasValue = analogRead(MQ2_PIN);
  if (gasValue > gasThreshold) 
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    sendSMS("⚠️ Alert: Gas Leakage Detected!");
    delay(10000);
  } 
  else 
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
  }
  delay(1000);
}
