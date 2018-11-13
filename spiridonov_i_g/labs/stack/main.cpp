#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
	Stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	Stack<int> stack2(stack1);

	cout << stack2.pop() << endl;
	cout << stack2.pop() << endl;

	stack2.push(10);
	stack2.push(20);
	stack2.push(30);
	cout << stack2.pop() << endl;
	cout << stack2.pop() << endl;
	stack2.push(40);
	cout << stack2.pop() << endl;
}