/*In this example, we define the PIR sensor pin as pirPin (pin 2 in this case). We also specify the inputSize, hiddenSize, outputSize, and learningRate for the MLP.

Inside the loop() function, we read the PIR sensor value using digitalRead(pirPin). The sensor output is either HIGH or LOW, indicating motion detection. We convert this value to MLP input format (0 or 1) and store it in the inputData array.

Then, we call mlp.predict() with the inputData array to obtain the MLP's output in the outputData array. If the output is above a threshold (in this case, 0.5), we consider it an intrusion and print a message via Serial.println(). You can replace the Serial.println() line with any desired action, such as activating an alarm or sending a notification.

Make sure you have the MLPLibrary files in the same directory as your sketch, and upload the sketch to your Arduino board. Connect the PIR sensor output pin to the designated pirPin on your Arduino. The code will continuously monitor the PIR sensor for motion and trigger the intrusion detection system when necessary.

Remember to adjust the MLP parameters and the threshold value based on your specific requirements and sensor characteristics.*/



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
