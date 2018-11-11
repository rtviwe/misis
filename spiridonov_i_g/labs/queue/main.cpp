#include <iostream>
#include "queue.hpp"

using namespace std;

int main()
{
	Queue q1(10);
	Queue q2(q1);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	cout << q1.pop() << endl;
	q1.enqueue(10);
}