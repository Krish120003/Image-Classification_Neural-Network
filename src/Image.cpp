#include <iostream>
#include <vector>
#include "Image.hpp" 

using namespace std;

// class Image
// {
// private:
//     // const static int size = 784;
//     /* data */
// public:
//     Image(/* args */);
//     ~Image();

//     int label;
//     vector<double> pixels;

//     void setLabel(int label);
//     void addPixel(double pixel);
// };

Image::Image()
{
    pixels = vector<double>();
}

Image::~Image()
{
}

void Image::setLabel(int label)
{
    this->label = label;
}

void Image::addPixel(double pixel)
{
    this->pixels.push_back(pixel);
}
