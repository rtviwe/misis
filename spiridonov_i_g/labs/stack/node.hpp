#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

template<typename T>
struct Node
{
	Node() = default;

	Node(T data, Node<T>* next)
		: data_(data), next_(next)
	{
	}

	T data_;
	Node<T>* next_;
};

#endif