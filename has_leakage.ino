#include <Arduino.h>

#define MQ2_PIN 34       
#define BUZZER_PIN 18    
#define LED_PIN 19       

int gasThreshold = 400;

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Gas Leakage Detection System Initialized...");
}

void loop() 
{
  int gasValue = analogRead(MQ2_PIN);

  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold) 
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.println("⚠️ Gas Leakage Detected!");
  }
 else 
 {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.println("✅ Safe Environment");
  }

  delay(1000); 
}
