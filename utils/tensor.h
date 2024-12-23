#ifndef TENSOR_H
#define TENSOR_H

#include <vector>

class Tensor {
public:
    Tensor(int height, int width, int depth);
    float& at(int h, int w, int d);
    const float& at(int h, int w, int d) const;
    int getHeight() const;
    int getWidth() const;
    int getDepth() const;

private:
    int height, width, depth;
    std::vector<float> data;
};

#endif // TENSOR_H
