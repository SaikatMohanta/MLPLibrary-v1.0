#include <MLPLibrary.h>

const int pirPin = 2;  // PIR sensor pin
const int inputSize = 1;
const int hiddenSize = 4;
const int outputSize = 1;
const float learningRate = 0.1;

MLPLibrary mlp(inputSize, hiddenSize, outputSize, learningRate);
float inputData[inputSize];
float outputData[outputSize];

void setup() {
  pinMode(pirPin, INPUT);
  mlp.initialize();
  Serial.begin(9600);
}

void loop() {
  // Read PIR sensor
  int pirValue = digitalRead(pirPin);

  // Convert PIR sensor value to MLP input format (0 or 1)
  inputData[0] = pirValue;

  // Predict using MLP
  mlp.predict(inputData, outputData);

  // Check if intrusion detected
  if (outputData[0] > 0.5) {
    Serial.println("Intrusion Detected!");
    // Perform necessary actions when intrusion is detected
  }

  delay(1000);
}
