#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

template<typename T>
struct Item
{
	Item() = default;

	Item(T data, Item<T>* next)
		: data_(data), next_(next)
	{
	}

	T data_;
	Item<T>* next_;
};

#endif