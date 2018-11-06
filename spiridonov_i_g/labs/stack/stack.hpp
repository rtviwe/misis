#pragma once
#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"

template<class T>
class Stack {
public:
	Stack() = default;

	Stack(const Stack& obj)
	{
		Node<T>* objHead = obj.head_;
		head_ = new Node<T>();

		while (objHead != nullptr)
		{
			Node<T>* newNode = new Node<T>();
			newNode->next_ = head_;
			head_ = newNode;

			head_->data_ = objHead->data_;
			head_ = head_->next_;
			objHead = objHead->next_;
		}
	}

	~Stack()
	{
		delete head_;
	}

	Stack& operator=(const Stack<T>& rhs)
	{
		if (this != &rhs)
		{
			Node<T>* newHead;
			delete head_;
			head_ = newHead;
			Node<T>* objHead = rhs.head_;

			while (rhs.head_ != nullptr)
			{
				Node<T>* newNode = new Node<T>();
				newNode->next_ = head_;
				head_ = newNode;

				head_->data_ = objHead->data_;
				head_ = head_->next_;
				objHead = objHead->next_;
			}
		}
		return *this;
	}

	const T& pop()
	{
		Node<T>* downerNode = head_->next_;
		delete head_;
		head_ = downerNode;

		if (head_->next_ == nullptr) {
			std::exception("Stack is empty");
		}

		return head_->data_;
	}

	void push(const T& data)
	{
		if (head_ == nullptr) {
			head_ = new Node<T>();
		}

		head_->data_ = data;

		Node<T>* upperNode = new Node<T>();
		upperNode->next_ = head_;
		head_ = upperNode;
	}
private:
	Node<T>* head_{ nullptr };
};

#endif