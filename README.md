# MLPLibrary-v1.0
A basic library to implement Artificial Neural Network with Multi Layer Perception architechture into your very own Arduino Boards. 
__________________________________________________________________________________________________________________________________________________________________
A Multi-Layer Perceptron (MLP) is a type of artificial neural network that consists of multiple layers of interconnected artificial neurons (perceptrons). It is a feedforward neural network, meaning the information flows in one direction, from the input layer to the output layer, without cycles or loops.

Here's a step-by-step explanation of how an MLP works:

Input Layer: The input layer receives the input data, which could be numerical values, binary values, or any other type of data representation. Each input neuron represents a feature or attribute of the data.

Hidden Layers: The MLP can have one or more hidden layers sandwiched between the input and output layers. Each hidden layer consists of multiple neurons. These layers are responsible for extracting and transforming the input data through a series of mathematical operations.

Neurons: Each neuron in the MLP takes inputs, applies weights to them, and passes the weighted sum through an activation function. The activation function introduces non-linearity to the network, allowing it to learn complex patterns and make non-linear predictions.

Weights and Biases: Each connection between neurons has an associated weight, which determines the strength or importance of that connection. The weights are adjusted during the training process to optimize the network's performance. Additionally, each neuron (except those in the input layer) typically has a bias term, which allows the network to learn offset values.

Activation Function: The activation function is applied to the weighted sum of inputs and biases in each neuron. It introduces non-linearities into the network, allowing it to model complex relationships in the data. Common activation functions include sigmoid, hyperbolic tangent (tanh), and rectified linear unit (ReLU).

Output Layer: The final layer in the MLP is the output layer. It produces the network's prediction or classification based on the transformed input data. The number of neurons in the output layer depends on the problem being solved. For example, in binary classification, there would typically be one output neuron representing the probability of one class, while in multi-class classification, there would be multiple output neurons, each representing the probability of a specific class.

Training: To train an MLP, a labeled training dataset is used. The weights and biases of the network are initially assigned random values. The network makes predictions on the training data, and the prediction errors (the differences between the predicted and actual outputs) are used to adjust the weights and biases through a process called backpropagation. Backpropagation calculates the gradient of the error with respect to the network parameters and updates them using an optimization algorithm like gradient descent. This process is repeated for multiple epochs until the network converges and the errors are minimized.

Forward Propagation: Once the MLP is trained, it can be used to make predictions on new, unseen data. The input is fed into the network's input layer, and the information flows forward through the hidden layers until reaching the output layer. The output of the output layer represents the network's prediction or classification for the given input.

MLPs have been widely used in various applications, including pattern recognition, image and speech recognition, time series analysis, and many more. They are powerful models capable of learning complex relationships in data, but they require careful design, parameter tuning, and training to achieve optimal performance.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
The above library implements a simplified version of a Multi-Layer Perceptron (MLP) neural network in the Arduino IDE. Let's go through the key components and their functionality:

MLPLibrary class:

It represents the MLP network and contains methods for initialization, training, and prediction.
Constructor:

It initializes the MLP network by specifying the input size, hidden layer size, output layer size, and learning rate.
initialize() method:

It initializes the weights and biases of the MLP network with random values between -1 and 1.
The input-hidden layer weights are stored in inputHiddenWeights.
The hidden-output layer weights are stored in hiddenOutputWeights.
The hidden layer biases are stored in hiddenLayerBiases.
The output layer biases are stored in outputLayerBiases.
train() method:

It performs a forward pass and backward pass to update the weights and biases based on the provided input and target.
In the forward pass, the input values are propagated through the network to calculate the output values.
In the backward pass, the errors are calculated for the output and hidden layers using the target values and the sigmoid activation function.
The weights and biases are updated based on the errors and learning rate using the gradient descent algorithm.
predict() method:

It performs a forward pass to predict the output values based on the provided input.
The input values are propagated through the network, and the output values are calculated using the sigmoid activation function.
sigmoid() function:

It implements the sigmoid activation function, which transforms the input value into a range between 0 and 1.
Overall, this library provides a simplified implementation of an MLP network suitable for simple tasks on Arduino boards. It can be used for basic classification or regression tasks by initializing, training, and predicting with the MLP network. However, please note that the implementation might not be as efficient or optimized as a full-scale MLP implementation, considering the resource constraints of the Arduino platform.

Overall, the MLPLibrary class provides the basic functionality to initialize an MLP network, train it using a training dataset, and obtain the output of the network for a given input.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------



