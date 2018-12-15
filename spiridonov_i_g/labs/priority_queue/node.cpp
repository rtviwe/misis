// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include "node.hpp"

Node::Node(int data, int priority, Node *next)
        : data_(data), priority_(priority), next_(next) {

}
