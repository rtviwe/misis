#pragma once
#ifndef STACK_HPP
#define STACK_HPP
#include "item.hpp"

template<typename T>
class Stack
{
public:
	Stack()
	{
		head_ = new Item<T>();
	}

	Stack(const Stack<T>& stack)
	{
		Item<T>* stackHead = stack.head_;
		head_ = new Item<T>();

		while (stackHead != nullptr && stackHead->next_ != nullptr)
		{
			
		}
	}

	Item<T>& top()
	{
		return *head_;
	}
	
	void push(Item<T>& item)
	{
		//head_->next_ = &item;
		//head_ = &item;
	}

	bool isEmpty()
	{
		return head_ == nullptr;
	}

	Stack& operator=(const Stack& stackToEqual)
	{

	}

	~Stack()
	{

	}
private:
	Item<T>* head_{ nullptr };
};

#endif