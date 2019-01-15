// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#ifndef QUEUE_ON_LIST_H
#define QUEUE_ON_LIST_H

class PriorityQueue {
public:
    PriorityQueue() = default;

    PriorityQueue(const PriorityQueue &priorityQueueOnList);

    ~PriorityQueue();

    PriorityQueue &operator=(const PriorityQueue &priorityQueue);

    int pop();

    void push(int value, int priority);

    bool isEmpty() const;

private:
    struct Node {
        int data{0};
        int priority{0};
        Node *nextNode{nullptr};
    };

    Node *head_{nullptr};
};

#endif //QUEUE_ON_LIST_H
