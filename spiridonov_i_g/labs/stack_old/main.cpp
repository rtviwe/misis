#include <iostream>
#include "stack.hpp"

using namespace std;

void testItems()
{
	Item<int> item1(1, nullptr);
	Item<int> item2(2, &item1);

	int result = item2.next_->data_;

	if (result == item1.data_)
	{
		std::cout << "Test Item next " << item1.data_ << " == " << result << " success" << endl;
	}
	else
	{
		std::cout << "Test Item next " << item1.data_ << " == " << result << " failed" << endl;
	}
}

int main()
{
	testItems();
	Stack<int> stack1;
	Item<int> item1(10, nullptr);
	stack1.push(item1);
	Stack<int> stack2(stack1);

	cout << stack1.top().data_ << endl;
	cout << stack2.top().data_ << endl;
}