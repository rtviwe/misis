#include "item.hpp"

template<typename T>
Item<T>::Item(const T data, Item<T>* next)
{
	this.data = data;
	this.next = next;
}
