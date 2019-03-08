#pragma once

template <class T>
class Node
{
protected:
	T data;
public:
	Node();
	Node(T data);
	void setData(T data);
	T getData();
};

template <class T>
Node<T>::Node()
{

}

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
}

template <class T>
void Node<T>::setData(T data)
{
	this->data = data;
}

template <class T>
T Node<T>::getData()
{
	return data;
}
