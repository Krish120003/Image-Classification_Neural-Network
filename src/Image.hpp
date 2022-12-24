#include <iostream>
#include <vector>

using namespace std;

class Image
{
private:
    // const static int size = 784;
    /* data */
public:
    Image(/* args */);
    ~Image();

    int label;
    vector<double> pixels;

    void setLabel(int label);
    void addPixel(double pixel);
};
