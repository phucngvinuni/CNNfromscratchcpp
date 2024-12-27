    #include "relu_layer.h"
    #include <algorithm>

    Tensor ReLULayer::forward(const Tensor& input) {
        Tensor output = input;
        for (int h = 0; h < input.getHeight(); ++h) {
            for (int w = 0; w < input.getWidth(); ++w) {
                for (int d = 0; d < input.getDepth(); ++d) {
                    output.at(h, w, d) = std::max(0.0f, input.at(h, w, d));
                }
            }
        }
        return output;
    }
