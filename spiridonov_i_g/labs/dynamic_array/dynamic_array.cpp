#include <iostream>
#include <algorithm>
#include "dynamic_array.hpp"

DynamicArray::DynamicArray(const int size)
    : size_(size), data_(new int[size_]) {
    for (int i(0); i < size_; i++) {
        data_[i] = 0;
    }
}

DynamicArray::DynamicArray(const DynamicArray& obj)
    : size_(obj.size_), data_(new int[size_]) {
    std::copy(obj.data_, obj.data_ + obj.size_, data_);
}

DynamicArray::~DynamicArray() {
    delete[] data_;
}

int DynamicArray::getSize() const {
    return size_;
}

void DynamicArray::setSize(const int size) {
    size_ = size;
    std::copy(data_, data_ + size_, data_);
}

int& DynamicArray::operator[](const int i) {
    if (i < 0) {
        throw std::out_of_range("Index should not be negative");
    }

    if (i > size_) {
        throw std::out_of_range("Index should be less than size of array");
    }

    return data_[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs) {
    if (this != &rhs) {
        if (size_ < rhs.size_) {
            int* newData(new int[rhs.size_]);
            delete[] data_;
            data_ = newData;
        }
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
        size_ = rhs.size_;
    }
    return *this;
}
