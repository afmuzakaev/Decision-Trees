#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(9600);
  if (!sht31.begin(0x44)) {
    Serial.println("Couldn't find SHT31");
    while (1) delay(1);
  }
}

void loop() {
  float humidity = sht31.readHumidity();
  float temperature = sht31.readTemperature();

  // Your decision tree model should provide a way to predict the class.
  // Here, we'll use a simplified rule for demonstration purposes.
  int predictedClass = predictClass(temperature, humidity);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Predicted Class: ");
  Serial.println(predictedClass);

  delay(2000);
}

int predictClass(float temperature, float humidity) {
  // Your actual decision tree prediction logic should be here.
  // You can use the decision rules from your trained model to predict the class.
  // For this example, let's assume a simple rule:
  if (temperature > 25.0 && humidity > 60.0) {
    return 1;
  } else {
    return 0;
  }
}
