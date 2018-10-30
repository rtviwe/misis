#include "item.hpp"

template<typename T>
Item<T>::Item()
{
	data{ nullptr };
}

template<typename T>
Item<T>::Item(const T data)
{
	this.data = data;
}

