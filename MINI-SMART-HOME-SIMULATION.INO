#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <ESP32Servo.h>

// Pin definitions
#define DHTPIN 4
#define DHTTYPE DHT22
#define SOIL_MOISTURE_PIN 34
#define RELAY_PIN 18
#define LED_PIN 2
#define SERVO_PIN 5

// Thresholds
const int moistureThreshold = 2000;
const float tempThreshold = 10.0;
const float humidityThreshold = 80.0;

// Components
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo waterPump;

void setup() {
  Serial.begin(115200);

  // Initialize sensors
  dht.begin();

  // Initialize LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  // Initialize output pins
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // In…
