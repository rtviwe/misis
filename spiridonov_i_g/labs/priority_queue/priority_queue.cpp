#include <bits/exception.h>
#include <stdexcept>
#include "priority_queue.hpp"

PriorityQueue::PriorityQueue(const PriorityQueue &priorityQueueOnList) {
    Node *copyNode = priorityQueueOnList.head_;
    while (copyNode != nullptr) {
        push(copyNode->data, copyNode->priority);
        copyNode = copyNode->nextNode;
    }
}

PriorityQueue::~PriorityQueue() {
    while (!isEmpty()) {
        pop();
    }
}

int PriorityQueue::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }

    int data = head_->data;

    Node *nodeToDelete = head_;
    head_ = head_->nextNode;
    delete nodeToDelete;

    return data;
}

void PriorityQueue::push(int value, int priority) {
    if (isEmpty()) {
        Node *newHead = new Node();
        newHead->data = value;
        newHead->priority = priority;

        head_ = newHead;
    } else {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->priority = priority;

        if (head_->priority <= priority) {
            Node *tempNode = head_;
            head_ = newNode;
            head_->nextNode = tempNode;
            return;
        }

        Node *findNode = head_;
        Node *next = head_->nextNode;
        while (next != nullptr) {
            if (next->priority <= priority) {
                Node *tempNode = findNode->nextNode;
                findNode->nextNode = newNode;
                newNode->nextNode = tempNode;
            }
            findNode = findNode->nextNode;
            next = next->nextNode;
        }
    }
}

bool PriorityQueue::isEmpty() const {
    return head_ == nullptr;
}

PriorityQueue &PriorityQueue::operator=(const PriorityQueue &priorityQueue) {
    if (this != &priorityQueue) {
        if (head_ == nullptr) {
            head_ = new Node();
        }
        head_->data = priorityQueue.head_->data;
        head_->priority = priorityQueue.head_->priority;

        Node *thisNode = head_;
        Node *copyNode = priorityQueue.head_->nextNode;

        while (copyNode != nullptr) {
            if (thisNode->nextNode == nullptr) {
                thisNode->nextNode = new Node();
            }
            thisNode = thisNode->nextNode;
            thisNode->data = copyNode->data;
            thisNode->priority = copyNode->priority;
            copyNode = copyNode->nextNode;
        }

        Node *restNode = thisNode->nextNode;

        while (restNode != nullptr) {
            Node *nodeToDelete = restNode;
            restNode = restNode->nextNode;
            delete nodeToDelete;
        }
    }

    return *this;
}
