#include "conv_layer.h"
#include <cmath>

ConvLayer::ConvLayer(int input_channels, int output_channels, int kernel_size, int stride, int padding)
    : input_channels(input_channels), output_channels(output_channels), kernel_size(kernel_size),
      stride(stride), padding(padding) {
    // Khởi tạo kernel và bias với giá trị ngẫu nhiên
    for (int i = 0; i < output_channels; ++i) {
        kernels.push_back(Tensor(kernel_size, kernel_size, input_channels));
        biases.push_back(0.0f); // Bias ban đầu bằng 0
    }
}

Tensor ConvLayer::forward(const Tensor& input) {
    int output_height = (input.getHeight() - kernel_size + 2 * padding) / stride + 1;
    int output_width = (input.getWidth() - kernel_size + 2 * padding) / stride + 1;

    Tensor output(output_height, output_width, output_channels);

    // Thực hiện tích chập
    for (int oc = 0; oc < output_channels; ++oc) {
        for (int h = 0; h < output_height; ++h) {
            for (int w = 0; w < output_width; ++w) {
                float value = 0.0f;
                for (int ic = 0; ic < input.getDepth(); ++ic) {
                    for (int kh = 0; kh < kernel_size; ++kh) {
                        for (int kw = 0; kw < kernel_size; ++kw) {
                            int ih = h * stride + kh - padding;
                            int iw = w * stride + kw - padding;
                            if (ih >= 0 && iw >= 0 && ih < input.getHeight() && iw < input.getWidth()) {
                                value += input.at(ih, iw, ic) * kernels[oc].at(kh, kw, ic);
                            }
                        }
                    }
                }
                output.at(h, w, oc) = value + biases[oc];
            }
        }
    }

    return output;
}
