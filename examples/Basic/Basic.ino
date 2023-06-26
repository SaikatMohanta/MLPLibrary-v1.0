#include "MLPLibrary.h"

MLPLibrary mlp(2, 4, 1, 0.1);  // Specify the input size, hidden size, output size, and learning rate

void setup() {
  // Initialize the MLP network
  mlp.initialize();
  Serial.begin(9600);
}

void loop() {
  float input[2] = {0.5, 0.3};
  float target[1] = {0.7};

  // Train the MLP network with the input and target
  mlp.train(input, target);

  // Predict the output using the trained network
  float output[1];
  mlp.predict(input, output);
  Serial.println(output[1]);

  // Do something with the output result
  // ...
}
