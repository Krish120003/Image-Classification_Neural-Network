#include <iostream>
#include <vector>

using namespace std;

class Neuron
{
private:
public:
    Neuron(int wSize);
    ~Neuron();
    double bias;
    vector<double> weights;
};

Neuron::Neuron(int wSize)
{
    bias = (rand() / (RAND_MAX / 2.0f)) - 1;
    for (int i = 0; i < wSize; i++)
    {
        weights.push_back((rand() / (RAND_MAX / 2.0f)) - 1);
    }
}

Neuron::~Neuron()
{
}