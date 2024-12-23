#include "tensor.h"

Tensor::Tensor(int height, int width, int depth)
    : height(height), width(width), depth(depth), data(height * width * depth, 0.0f) {}

float& Tensor::at(int h, int w, int d) {
    return data[(h * width + w) * depth + d];
}

const float& Tensor::at(int h, int w, int d) const {
    return data[(h * width + w) * depth + d];
}

int Tensor::getHeight() const { return height; }
int Tensor::getWidth() const { return width; }
int Tensor::getDepth() const { return depth; }
