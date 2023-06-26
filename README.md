# MLPLibrary-v1.0
A basic library to implement Artificial Neural Network with Multi Layer Perception architechture into your very own Arduino Boards. 
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
Certainly! Let's go through the functions defined in the custom MLPLibrary.h and understand their functionalities:

1. `MLPLibrary(int inputSize, int hiddenSize, int outputSize, float learningRate)`: The constructor of the MLPLibrary class. It initializes the MLP architecture by specifying the sizes of the input layer (`inputSize`), hidden layer (`hiddenSize`), and output layer (`outputSize`). The `learningRate` parameter determines the rate at which the network learns during training.

2. `void initialize()`: This function initializes the weights and biases of the MLP network. It randomly assigns values to the weights and biases within a certain range.

3. `void train(float input[MAX_INPUT_SIZE], float target[MAX_OUTPUT_SIZE])`: This function performs the training of the MLP network. It takes an input array (`input`) and a target array (`target`) as parameters. The MLP is fed with the input, and the weights and biases are updated using the backpropagation algorithm to minimize the difference between the network's output and the target values.

4. `void feedForward(float input[MAX_INPUT_SIZE])`: This function performs the forward propagation step of the MLP. It takes an input array (`input`) as a parameter and calculates the activations of the hidden layer and output layer using the current weights and biases.

5. `void backpropagation(float target[MAX_OUTPUT_SIZE])`: This function performs the backpropagation step of the MLP. It takes a target array (`target`) as a parameter and updates the weights and biases of the network based on the calculated errors. The backpropagation algorithm calculates the error at each layer and adjusts the weights and biases accordingly.

6. `float* getOutput()`: This function returns a pointer to the output layer of the MLP network. It can be used to retrieve the calculated output values after feeding forward an input through the network.

Overall, the MLPLibrary class provides the basic functionality to initialize an MLP network, train it using a training dataset, and obtain the output of the network for a given input.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------



