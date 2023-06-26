#include "MLPLibrary.h"

MLPLibrary mlp(2, 3, 1, 0.1);  // Specify the input size, hidden size, output size, and learning rate
int pirPin = 2;  // PIR sensor pin

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);

  // Initialize the MLP network
  mlp.initialize();
}

void loop() {
  // Read PIR sensor state
  int pirState = digitalRead(pirPin);

  // Prepare input array
  float input[2];
  input[0] = pirState;
  input[1] = random(0, 100) / 100.0;  // Simulate additional sensor data

  // Train the MLP network with the input and target
  float target[1] = {pirState};
  mlp.train(input, target);

  // Get the output from the trained network
  float* output = mlp.getOutput();

  // Print results
  Serial.print("PIR state: ");
  Serial.print(pirState);
  Serial.print(" | Output: ");
  Serial.println(output[0]);

  delay(1000);
}
