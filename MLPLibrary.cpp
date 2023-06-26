#include "MLPLibrary.h"

MLPLibrary::MLPLibrary(int inputSize, int hiddenSize, int outputSize, float learningRate) {
  numInputs = inputSize;
  numHidden = hiddenSize;
  numOutputs = outputSize;
  this->learningRate = learningRate;
}

void MLPLibrary::initialize() {
  // Initialize the weights and biases with random values between -1 and 1
  for (int i = 0; i < numInputs; i++) {
    for (int j = 0; j < numHidden; j++) {
      inputHiddenWeights[i][j] = random(-100, 100) / 100.0;
    }
  }

  for (int i = 0; i < numHidden; i++) {
    for (int j = 0; j < numOutputs; j++) {
      hiddenOutputWeights[i][j] = random(-100, 100) / 100.0;
    }
    hiddenLayerBiases[i] = random(-100, 100) / 100.0;
  }

  for (int i = 0; i < numOutputs; i++) {
    outputLayerBiases[i] = random(-100, 100) / 100.0;
  }
}

void MLPLibrary::train(float input[MAX_INPUT_SIZE], float target[MAX_OUTPUT_SIZE]) {
  // Forward pass
  for (int i = 0; i < numInputs; i++) {
    inputLayer[i] = input[i];
  }

  for (int i = 0; i < numHidden; i++) {
    float sum = 0.0;
    for (int j = 0; j < numInputs; j++) {
      sum += inputLayer[j] * inputHiddenWeights[j][i];
    }
    hiddenLayer[i] = sigmoid(sum + hiddenLayerBiases[i]);
  }

  for (int i = 0; i < numOutputs; i++) {
    float sum = 0.0;
    for (int j = 0; j < numHidden; j++) {
      sum += hiddenLayer[j] * hiddenOutputWeights[j][i];
    }
    outputLayer[i] = sigmoid(sum + outputLayerBiases[i]);
  }

  // Backward pass
  for (int i = 0; i < numOutputs; i++) {
    outputLayerErrors[i] = (target[i] - outputLayer[i]) * outputLayer[i] * (1 - outputLayer[i]);
  }

  for (int i = 0; i < numHidden; i++) {
    float sum = 0.0;
    for (int j = 0; j < numOutputs; j++) {
      sum += outputLayerErrors[j] * hiddenOutputWeights[i][j];
    }
    hiddenLayerErrors[i] = sum * hiddenLayer[i] * (1 - hiddenLayer[i]);
  }

  // Update weights and biases
  for (int i = 0; i < numInputs; i++) {
    for (int j = 0; j < numHidden; j++) {
      inputHiddenWeights[i][j] += learningRate * hiddenLayerErrors[j] * inputLayer[i];
    }
  }

  for (int i = 0; i < numHidden; i++) {
    for (int j = 0; j < numOutputs; j++) {
      hiddenOutputWeights[i][j] += learningRate * outputLayerErrors[j] * hiddenLayer[i];
    }
    hiddenLayerBiases[i] += learningRate * hiddenLayerErrors[i];
  }

  for (int i = 0; i < numOutputs; i++) {
    outputLayerBiases[i] += learningRate * outputLayerErrors[i];
  }
}

void MLPLibrary::predict(float input[MAX_INPUT_SIZE], float output[MAX_OUTPUT_SIZE]) {
  // Forward pass
  for (int i = 0; i < numInputs; i++) {
    inputLayer[i] = input[i];
  }

  for (int i = 0; i < numHidden; i++) {
    float sum = 0.0;
    for (int j = 0; j < numInputs; j++) {
      sum += inputLayer[j] * inputHiddenWeights[j][i];
    }
    hiddenLayer[i] = sigmoid(sum + hiddenLayerBiases[i]);
  }

  for (int i = 0; i < numOutputs; i++) {
    float sum = 0.0;
    for (int j = 0; j < numHidden; j++) {
      sum += hiddenLayer[j] * hiddenOutputWeights[j][i];
    }
    output[i] = sigmoid(sum + outputLayerBiases[i]);
  }
}

float MLPLibrary::sigmoid(float x) {
  return 1.0 / (1.0 + exp(-x));
}
