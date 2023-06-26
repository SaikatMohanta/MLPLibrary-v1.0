#include "MLPLibrary.h"

MLPLibrary::MLPLibrary(int inputSize, int hiddenSize, int outputSize, float learningRate) {
  numInputs = inputSize;
  numHidden = hiddenSize;
  numOutputs = outputSize;
  this->learningRate = learningRate;
}

void MLPLibrary::initialize() {
  // Initialize the weights and biases randomly
  randomSeed(analogRead(0));

  for (int i = 0; i < numHidden; i++) {
    hiddenBiases[i] = random(-100, 100) / 100.0;

    for (int j = 0; j < numInputs; j++) {
      hiddenWeights[i][j] = random(-100, 100) / 100.0;
    }
  }

  for (int i = 0; i < numOutputs; i++) {
    outputBiases[i] = random(-100, 100) / 100.0;

    for (int j = 0; j < numHidden; j++) {
      outputWeights[i][j] = random(-100, 100) / 100.0;
    }
  }
}

void MLPLibrary::feedForward(float input[MAX_INPUT_SIZE]) {
  // Calculate hidden layer activations
  for (int i = 0; i < numHidden; i++) {
    float sum = hiddenBiases[i];
    for (int j = 0; j < numInputs; j++) {
      sum += hiddenWeights[i][j] * input[j];
    }
    hiddenLayer[i] = 1.0 / (1.0 + exp(-sum));
  }

  // Calculate output layer activations
  for (int i = 0; i < numOutputs; i++) {
    float sum = outputBiases[i];
    for (int j = 0; j < numHidden; j++) {
      sum += outputWeights[i][j] * hiddenLayer[j];
    }
    outputLayer[i] = 1.0 / (1.0 + exp(-sum));
  }
}

void MLPLibrary::backpropagation(float target[MAX_OUTPUT_SIZE]) {
  // Calculate output layer errors
  float outputErrors[MAX_OUTPUT_SIZE];
  for (int i = 0; i < numOutputs; i++) {
    outputErrors[i] = (target[i] - outputLayer[i]) * outputLayer[i] * (1.0 - outputLayer[i]);
  }

  // Calculate hidden layer errors
  float hiddenErrors[MAX_HIDDEN_SIZE];
  for (int i = 0; i < numHidden; i++) {
    float sum = 0.0;
    for (int j = 0; j < numOutputs; j++) {
      sum += outputWeights[j][i] * outputErrors[j];
    }
    hiddenErrors[i] = sum * hiddenLayer[i] * (1.0 - hiddenLayer[i]);
  }

  // Update output weights and biases
  for (int i = 0; i < numOutputs; i++) {
    for (int j = 0; j < numHidden; j++) {
      outputWeights[i][j] += learningRate * outputErrors[i] * hiddenLayer[j];
    }
    outputBiases[i] += learningRate * outputErrors[i];
  }

  // Update hidden weights and biases
  for (int i = 0; i < numHidden; i++) {
    for (int j = 0; j < numInputs; j++) {
      hiddenWeights[i][j] += learningRate * hiddenErrors[i] * input[j];
    }
    hiddenBiases[i] += learningRate * hiddenErrors[i];
  }
}

void MLPLibrary::train(float input[MAX_INPUT_SIZE], float target[MAX_OUTPUT_SIZE]) {
  feedForward(input);
  backpropagation(target);
}

float* MLPLibrary::getOutput() {
  return outputLayer;
}

