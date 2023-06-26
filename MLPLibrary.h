#ifndef MLPLibrary_h
#define MLPLibrary_h

#include "Arduino.h"

#define MAX_INPUT_SIZE 10
#define MAX_HIDDEN_SIZE 10
#define MAX_OUTPUT_SIZE 10

class MLPLibrary {
public:
  MLPLibrary(int inputSize, int hiddenSize, int outputSize, float learningRate);

  void initialize();
  void train(float input[MAX_INPUT_SIZE], float target[MAX_OUTPUT_SIZE]);
  void predict(float input[MAX_INPUT_SIZE], float output[MAX_OUTPUT_SIZE]);

private:
  int numInputs;
  int numHidden;
  int numOutputs;
  float learningRate;

  float inputLayer[MAX_INPUT_SIZE];
  float hiddenLayer[MAX_HIDDEN_SIZE];
  float outputLayer[MAX_OUTPUT_SIZE];

  float inputHiddenWeights[MAX_INPUT_SIZE][MAX_HIDDEN_SIZE];
  float hiddenOutputWeights[MAX_HIDDEN_SIZE][MAX_OUTPUT_SIZE];

  float hiddenLayerBiases[MAX_HIDDEN_SIZE];
  float outputLayerBiases[MAX_OUTPUT_SIZE];

  float hiddenLayerErrors[MAX_HIDDEN_SIZE];
  float outputLayerErrors[MAX_OUTPUT_SIZE];

  float sigmoid(float x);
};

#endif
