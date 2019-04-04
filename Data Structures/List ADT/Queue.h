#pragma once
#include "List.h"
#include "Node.h"

template <class T>
class Queue : public List<T>
{
private:
	int QSize;
	Node<T>* Q_front;
	Node<T>* Q_back;
public:
	Queue<T>();
	~Queue<T>();
	T Front();
	void Enqueue(T val);
	void Dequeue();
	bool isQEmpty();
};

template<class T>
Queue<T>::Queue()
{
	this->Q_front = nullptr;
	this->Q_back = nullptr;
	QSize = 0;
}

template<class T>
Queue<T>::~Queue()
{
	std::cout << "Deleting Queue...\n";
}

template<class T>
T Queue<T>::Front()
{
	return Q_front->Data;
}

template<class T>
void Queue<T>::Enqueue(T val)
{
	Node<T>* QNode = new Node<T>(val);

	if (QSize == 0)
	{
		QNode->Next = nullptr;
		Q_front = QNode;
		Q_back = Q_front;
	}
	else
	{
		Q_back->Next = QNode;
		Q_back = QNode;
	}
	QSize++;
}

template<class T>
void Queue<T>::Dequeue()
{
	if (QSize == 0)
	{
		return;
	}

	Node<T>* QNode = Q_front;
	Q_front = Q_front->Next;
	delete QNode;
	QSize--;
}

template<class T>
inline bool Queue<T>::isQEmpty()
{
	return (QSize <= 0);
}
