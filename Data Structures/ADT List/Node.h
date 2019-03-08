#pragma once
#include <iostream>
#include <string>
template <class T>
class Node
{
public:
	Node<T>(T data = NULL);
	Node<T>* next;
	T data;
	friend std::ostream& operator<<(std::ostream& os, const Node<T>& c)
	{
		return os << "Data: " << c.data;
	};
	void setData(T value);
	void setNext(Node<T>* value);
	T getData();
	Node* getNext();
};

template <class T>
Node<T>::Node(T n):data(n), next(nullptr)
{

}

template<class T>
void Node<T>::setData(T value)
{
	data = value;
}

template<class T>
void Node<T>::setNext(Node<T>* value)
{
	next = value;
}

template<class T>
T Node<T>::getData()
{
	return data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return next;
}
