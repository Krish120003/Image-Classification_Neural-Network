cmake_minimum_required(VERSION 3.0.0)
project(MNIST_NeuralNetwork VERSION 0.1.0)

file(GLOB TARGET_SRC "./src/*.cpp")
add_executable(main ${TARGET_SRC})
