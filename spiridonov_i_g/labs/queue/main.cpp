#include <iostream>
#include "queue.hpp"

using namespace std;

int main()
{
	Queue queue1(10);
	Queue queue2(queue1);
	queue1.enqueue(1);
	queue1.enqueue(2);
	queue1.enqueue(3);
	queue1.enqueue(4);
	queue1.enqueue(5);
	queue1.enqueue(6);
	queue1.enqueue(7);
	queue1.enqueue(8);
	queue1.enqueue(9);
	cout << "queue1.pop() = " << queue1.pop() << endl;
	queue1.enqueue(10);
	cout << "queue1.enqueue(10) = " << queue1.top() << endl;
	cout << "queue1.top() = " << queue1.top() << endl;
}
