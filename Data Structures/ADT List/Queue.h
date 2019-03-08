#pragma once
#include "Node.h"

template <class T>
class Queue : public Node<T>
{
public:
	Queue<T>();
	~Queue<T>();
	void Enqueue(T element);
	void Dequeue();
	bool isQEmpty();
	int size();
	T first();

private:
	Node<T>* frontPtr;
	Node<T>* backPtr;
	int count;
};

template<class T>
Queue<T>::Queue()
{
	int count = NULL;
	this->frontPtr = nullptr;	
	this->backPtr = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
	std::cout << "Clearing mem...\n";
}

template<class T>
void Queue<T>::Enqueue(T element)
{
	Node<T>* tmp = new Node<T>();
	tmp->setData(element);
	tmp->setNext(nullptr);

	if (isQEmpty())
	{
		frontPtr = backPtr = tmp;
	}
	else
	{
		backPtr->setNext(tmp);
		backPtr = tmp;
	}
	count++;
}

template<class T>
void Queue<T>::Dequeue()
{
	if (isQEmpty())
		std::cout << "Queue is empty...\n";
	T ret = frontPtr->getData();
	Node<T>* tmp = frontPtr;
	frontPtr = frontPtr->getNext();
	count--;
	delete tmp;

}

template<class T>
bool Queue<T>::isQEmpty()
{
	return count == NULL ? true : false;
}

template<class T>
int Queue<T>::size()
{
	return count;
}

template<class T>
T Queue<T>::first()
{
	if (isQEmpty())
		std::cout << "Queue is empty..\n";
	return frontPtr->getData();
}

