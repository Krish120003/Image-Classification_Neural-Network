#include <iostream>
#include <vector>
#include "Neuron.cpp"

using namespace std;

vector<double> multVec(vector<double> vec1, vector<double> vec2)
{
    vector<double> result;
    for (int i = 0; i < vec1.size(); i++)
    {
        result.push_back(vec1[i] * vec2[i]);
    }
    return result;
}

double vecSum(vector<double> vec)
{
    double sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }

    return sum;
}

class DenseLayer
{
private:
    vector<Neuron> neurons;

public:
    int size;
    DenseLayer(int size, int inputSize);
    ~DenseLayer();

    vector<double> push(vector<double> input);
};

DenseLayer::DenseLayer(int size, int inputSize)
{
    this->size = size;
    for (int i = 0; i < size; i++)
    {
        neurons.push_back(Neuron(inputSize));
    }
}

DenseLayer::~DenseLayer()
{
}

vector<double> DenseLayer::push(vector<double> input)
{
    vector<double> result;
    for (int i = 0; i < size; i++)
    {
        result.push_back(vecSum(multVec(neurons[i].weights, input)) + neurons[i].bias);
    }
    return result;
}
