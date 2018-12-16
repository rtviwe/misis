// Copyright 2018 by Igor Spiridonov under Free Public License 1.0.0

#include <iostream>
#include "../priority_queue.hpp"

using namespace std;

int main() {
    PriorityQueue queue1(10);
    PriorityQueue queue2(queue1);
    queue1.enqueue(1, 10);
    queue1.enqueue(2, 3);
    queue1.enqueue(3, 9);
    queue1.enqueue(4, 5);
    queue1.enqueue(5, 0);

    cout << queue1.data_[0] << endl;
    cout << queue1.data_[1] << endl;
    cout << queue1.data_[2] << endl;
    cout << queue1.data_[3] << endl;
    cout << queue1.data_[4] << endl;

    cout << endl;

    cout << queue1.priorities_[0] << endl;
    cout << queue1.priorities_[1] << endl;
    cout << queue1.priorities_[2] << endl;
    cout << queue1.priorities_[3] << endl;
    cout << queue1.priorities_[4] << endl;
}