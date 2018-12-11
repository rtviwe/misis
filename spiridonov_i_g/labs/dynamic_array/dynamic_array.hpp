// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

class DynamicArray {
 public:
    DynamicArray() = default;
    explicit DynamicArray(const int size);
    DynamicArray(const DynamicArray& obj);

    ~DynamicArray();

    int getSize() const;
    void setSize(const int size);

    std::ostream& writeTo(std::ostream& ostrm) const;

    int& operator[](const int i);
    DynamicArray& operator=(const DynamicArray& rhs);

 private:
    int size_ { 0 };
    int* data_ { nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, const DynamicArray& dynamicArray);

#endif
