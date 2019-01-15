#include <iostream>
#include "../../labs/priority_queue/priority_queue.hpp"

using namespace std;

int main() {
    PriorityQueue q1;
    q1.push(1, 1);
    PriorityQueue q2(q1);
    cout << "1 = " << q1.pop() << endl;
    cout << "1 = " << q2.pop() << endl;

    cout << "true = " << (q2.isEmpty() ? "true" : "false") << endl;

    q2.push(2, 3);
    cout << "false = " << (q2.isEmpty() ? "true" : "false") << endl;

    PriorityQueue q3;
    q3.push(1, 1);
    q3.push(2, 2);
    q3.push(3, 3);
    cout << "3 = " << q3.pop() << endl;

    PriorityQueue q4;
    q4.push(1, 1);
    q4.push(5, 5);
    q4.push(4, 4);
    q4.push(3, 3);
    cout << "5 = " << q4.pop() << endl;

    PriorityQueue q5;
    q5.push(1, 1);
    q5.pop();
    try {
        q5.pop();
    } catch (std::runtime_error &error) {
        cout << "Stack is empty" << endl;
    }

    PriorityQueue q6;
    q6.push(6, -1);
    q6.push(10, -5);
    cout << "6 = " << q6.pop() << endl;

    PriorityQueue q7;
    q7.push(1, 1);
    q7.push(10, 10);
    q7.push(13, 13);
    q7.push(2, 2);
    cout << "13 = " << q7.pop() << endl;
    cout << "10 = " << q7.pop() << endl;
    cout << "2 = " << q7.pop() << endl;
    cout << "1 = " << q7.pop() << endl;

    PriorityQueue q8;
    q8.push(1, 1);
    q8.push(1, 1);
    q8.push(1, 1);
    cout << "1 = " << q8.pop() << endl;
    cout << "1 = " << q8.pop() << endl;
    cout << "1 = " << q8.pop() << endl;

    PriorityQueue q9;
    q9.push(33, 0);
    q9 = q9;
    cout << "33 = " << q9.pop() << endl;

    PriorityQueue q10;
    q10.push(17, 2);
    PriorityQueue q11;
    q11 = q10;
    cout << "17 = " << q11.pop() << endl;

    return 0;
}
