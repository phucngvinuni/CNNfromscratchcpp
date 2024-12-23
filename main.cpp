#include "layers/conv_layer.h"
#include "layers/relu_layer.h"
#include "utils/tensor.h"
#include <iostream>

int main() {
    // Tạo input giả lập
    Tensor input(32, 32, 3); // Ảnh RGB 32x32

    // Tạo lớp tích chập
    ConvLayer conv1(3, 8, 3, 1, 1); // 8 kernel 3x3, stride=1, padding=1
    Tensor conv_output = conv1.forward(input);

    // Tạo lớp ReLU
    ReLULayer relu1;
    Tensor relu_output = relu1.forward(conv_output);

    // In kích thước đầu ra
    std::cout << "Output size: " << relu_output.getHeight() << "x" << relu_output.getWidth() << "x" << relu_output.getDepth() << std::endl;

    return 0;
}
