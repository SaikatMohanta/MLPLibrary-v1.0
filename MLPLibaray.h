#ifndef MLPLibrary_h
#define MLPLibrary_h

#include <Arduino.h>

#define MAX_INPUT_SIZE 10
#define MAX_HIDDEN_SIZE 10

class MLPLibrary {
public:
  MLPLibrary(int inputSize, int hiddenSize, int outputSize, float learningRate);
  
  void initialize();
  void train(float input[MAX_INPUT_SIZE], float target[MAX_OUTPUT_SIZE]);
  void feedForward(float input[MAX_INPUT_SIZE]);
  void backpropagation(float target[MAX_OUTPUT_SIZE]);
  float* getOutput();

private:
  int numInputs;
  int numHidden;
  int numOutputs;
  float learningRate;

  float hiddenWeights[MAX_HIDDEN_SIZE][MAX_INPUT_SIZE];
  float outputWeights[MAX_OUTPUT_SIZE][MAX_HIDDEN_SIZE];
  float hiddenBiases[MAX_HIDDEN_SIZE];
  float outputBiases[MAX_OUTPUT_SIZE];

  float hiddenLayer[MAX_HIDDEN_SIZE];
  float outputLayer[MAX_OUTPUT_SIZE];
};

#endif
