// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

template<typename T>
struct Node {
    Node() = default;

    Node(const T data, Node<T>* next)
        : data_(data), next_(next) {
    }

    T data_;
    Node<T>* next_;
};

#endif
