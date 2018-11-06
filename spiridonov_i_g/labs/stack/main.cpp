#include <iostream>
#include "stack.hpp"

using namespace std;

int main()
{
	Stack<int> stack1;
	stack1.push(1);
	stack1.push(2);
	Stack<int> stack2(stack1);

	cout << stack1.pop() << endl;
	cout << stack1.pop() << endl;
}