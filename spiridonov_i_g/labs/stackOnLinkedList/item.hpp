#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

template<typename T>
struct Item
{
	Item();
	explicit Item(const T data);

	T data;
	Item* next;
};

#endif