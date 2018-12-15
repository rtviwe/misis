// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

class PriorityQueue {
public:
    PriorityQueue() = default;

    PriorityQueue(int size);

    bool empty();

    int size();

    int front();

    int push();

    int pop();

private:
    int _size;
    int *_data;
    int _index;
};
