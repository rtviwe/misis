// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "node.hpp"

template<class T>
class Stack {
 public:
    Stack() = default;

    Stack(const Stack& stack) {
        Stack<T> newStack;
        Node<T>* temp = stack.head_;

        while (temp != nullptr) {
            newStack.push(temp->data_);
            temp = temp->next_;
        }

        temp = newStack.head_;

        while (temp != nullptr) {
            push(temp->data_);
            temp = temp->next_;
        }
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    Stack& operator=(const Stack<T>& rhs) {
        Stack<T> newStack;
        Node<T>* temp = rhs.head_;

        while (temp != nullptr) {
            newStack.push(temp->data_);
            temp = temp->next_;
        }

        temp = newStack.head_;

        while (temp != nullptr) {
            push(temp->data_);
            temp = temp->next_;
        }

        return *this;
    }

    const T& pop() {
        if (!isEmpty()) {
            Node<T>* oldNode(head_);
            head_ = oldNode->next_;
            delete oldNode;
        } else {
            throw std::exception("Stack is empty");
        }
    }

    void push(const T& data) {
        head_ = new Node<T>(data, head_);
    }

    const T& top() const {
        if (!isEmpty()) {
            return head_->data_;
        } else {
            throw std::exception("Stack is empty");
        }
    }

    bool isEmpty() const {
        return (head_ == nullptr);
    }

    std::ostream& writeTo(std::ostream& ostrm) const {
        Node<T>* temp = head_;
        while (temp != nullptr) {
            ostrm << temp->data_ << " ";
            temp = temp->next_;
        }
        return ostrm;
    }

 private:
    Node<T>* head_{ nullptr };
};

template<class T>
inline std::ostream& operator<<(std::ostream& ostrm, const Stack<T>& a) {
    return a.writeTo(ostrm);
}

#endif
