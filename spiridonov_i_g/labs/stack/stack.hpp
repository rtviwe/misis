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
		Node<T>* old_head = obj.head_;
		head_ = new Node<T>(old_head->data_, old_head->next_);
		Node<T> head_ptr = *head_;

		while (old_head->next_ != nullptr)
		{
			head_->next_ = new Node<T>(old_head->next_->data_, old_head->next_->next_);

			old_head = old_head->next_;
			head_ = head_->next_;
		}

		*head_ = head_ptr;
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

			while (objHead->next_ != nullptr)
			{
				head_->next_ = new Node<T>(objHead->next_->data_, objHead->next_->next_);

				objHead = objHead->next_;
				head_ = head_->next_;
			}
		}
		return *this;
	}

	const T& pop()
	{
		Node<T>* nextNode = head_->next_;
		delete head_;
		head_ = nextNode;

		if (head_ == nullptr) {
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