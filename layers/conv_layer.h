#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "../utils/tensor.h"
#include <vector>

class ConvLayer {
public:
    ConvLayer(int input_channels, int output_channels, int kernel_size, int stride, int padding);
    Tensor forward(const Tensor& input);

private:
    int input_channels, output_channels, kernel_size, stride, padding;
    std::vector<Tensor> kernels; // Mỗi kernel là một tensor
    std::vector<float> biases;
};

#endif // CONV_LAYER_H
