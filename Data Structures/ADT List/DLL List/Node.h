#pragma once
#include <iostream>

template <class T>
class Node
{
public:
	Node<T>(T Data = T());
	void setData(T value);
	T getData();
	Node* getNext();
	Node* getPrev();
	void setNext(Node<T>* Data);
	void setPrev(Node<T>* Data);
	Node<T>* Prev;
	Node<T>* Next;
	T Data;
};

/*
 *	Node class Constructor
 */
template<class T>
Node<T>::Node(T n):Data(n)
{
	this->Prev = nullptr;
	this->Next = nullptr;
}

/*
 *	Set Data to the value parameter
 */
template<class T>
void Node<T>::setData(T value)
{
	Data = value;
}

/*
 *	Get the Data Value
 */
template<class T>
T Node<T>::getData()
{
	return Data;
}

/*
 *	Get the next node
 */
template<class T>
Node<T>* Node<T>::getNext()
{
	return Next;
}

/*
 *	Get the previous node
 */
template<class T>
Node<T>* Node<T>::getPrev()
{
	return Prev;
}

/*
 *	Set the next node
 */
template<class T>
void Node<T>::setNext(Node<T>* value)
{
	Next = value;
}

/*
 *	Set the previous node
 */
template<class T>
void Node<T>::setPrev(Node<T>* value)
{
	Prev = value;
}

