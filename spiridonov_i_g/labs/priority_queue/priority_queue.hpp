// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#pragma once
#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

class PriorityQueue {
public:
    PriorityQueue() = default;

    explicit PriorityQueue(int size);

    PriorityQueue(const PriorityQueue &obj);

    ~PriorityQueue();

    bool isEmpty();

    bool isEmpty() const;

    bool isFull();

    bool isFull() const;

    int top();

    int top() const;

    int pop();

    void enqueue(int value, int priority);

    PriorityQueue &operator=(const PriorityQueue &rhs);

private:
    int *data_;
    int *priorities_;
    int size_;
    int end_;
};

#endif
