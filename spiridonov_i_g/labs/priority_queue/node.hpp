// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

struct Node {
    Node() = default;

    Node(int data, int priority, Node *next);

    int data_;
    int priority_;
    Node *next_;
};

#endif //PROJECT_NODE_H
