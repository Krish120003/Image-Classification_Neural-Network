#include <iostream>
#include "Image.hpp" 
#include "Network/DenseLayer.cpp"
#include <cmath>

using namespace std;

unsigned int getNextInt(FILE *file)
{
    unsigned char buffer[4];
    fread(buffer, 1, 4, file);
    unsigned int result = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    return result;
}

unsigned char getNextChar(FILE *file)
{
    unsigned char buffer[1];
    fread(buffer, 1, 1, file);
    return buffer[0];
}

vector<Image> loadMnistData()
{
    std::cout << "Loading MNIST Data..." << std::endl;
    vector<Image> images = vector<Image>();

    FILE *labelFile = fopen("data/train-labels-idx1-ubyte", "rb");
    FILE *imageFile = fopen("data/train-images-idx3-ubyte", "rb");
    if (labelFile == nullptr || imageFile == nullptr)
    {
        std::cout << "Failed to open file" << std::endl;
        return images;
    }

    int label_magic_number = getNextInt(labelFile);
    int size = getNextInt(labelFile);
    int image_magic_number = getNextInt(imageFile);
    int image_size = getNextInt(imageFile);

    // Width and height of images
    int height = getNextInt(imageFile);
    int width = getNextInt(imageFile);

    for (int i = 0; i < 10; i++)
    {
        Image image = Image();
        image.setLabel(getNextChar(labelFile));

        for (int j = 0; j < height * width; j++)
        {
            image.addPixel((double)getNextChar(imageFile) / 255.0f);
        }

        images.push_back(image);
    }

    fclose(labelFile);
    fclose(imageFile);

    return images;
}

vector<double> relu(vector<double> input)
{
    vector<double> result;
    for (int i = 0; i < input.size(); i++)
    {
        result.push_back(input[i] > 0 ? input[i] : 0);
    }
    return result;
}

vector<double> softmax(vector<double> input)
{
    double E = 2.7182818284590452353602874713527;
    vector<double> result;
    double sum = 0;
    for (int i = 0; i < input.size(); i++)
    {
        sum += exp(input[i]);
    }

    for (int i = 0; i < input.size(); i++)
    {
        result.push_back(exp(input[i]) / sum);
    }

    return result;
}

double categorical_crossentropy(vector<double> y_true, vector<double> y_pred)
{
    double sum = 0;
    for (int i = 0; i < y_true.size(); i++)
    {
        sum += y_true[i] * log(y_pred[i]);
    }

    return -sum;
}

int main()
{
    // Create Layer 0 - input
    vector<Image> images = loadMnistData();
    int inputSize = 28 * 28;

    DenseLayer l1 = DenseLayer(3, 2);
    DenseLayer l2 = DenseLayer(2, 3);

    vector<double> in = vector<double>();
    in.push_back(1);
    in.push_back(1);

    vector<double> res1 = l1.push(in);
    vector<double> out = l2.push(res1);

    for (int i = 0; i < out.size(); i++)
    {
        std::cout << out[i] << std::endl;
    }

    // Do a pass through and see the output
    // vector<double> layer1Result = vector<double>();
    // for (int i = 0; i < layer1Size; i++)
    // {
    //     layer1Result.push_back(vecSum(multVec(layer1[i].weights, images[0].pixels)) + layer1[i].bias);
    //     cout << "Layer 1 " << i << " Result: " << layer1Result[i] << endl;
    // }

    // vector<double> layer2Result = vector<double>();
    // for (int i = 0; i < layer2Size; i++)
    // {
    //     layer2Result.push_back(vecSum(multVec(layer2[i].weights, images[0].pixels)) + layer2[i].bias);
    //     cout << "Layer 2 " << i << " Result: " << layer2Result[i] << endl;
    // }

    return 0;
}
