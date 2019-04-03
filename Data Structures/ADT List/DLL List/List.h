#pragma once
#include "Node.h"

template <class T>
class Iterator
{
private:
	Node<T>* v;
	Iterator(Node<T>* u) { v = u; }
public:
	T& operator*();
	bool operator==(const Iterator& p) const;
	bool operator!=(const Iterator& p) const;
	Iterator& operator++();
	Iterator& operator--();
	//friend class List<T>
};

template <class T>
class List : public Node<T>
{
public:
	List<T>();
	~List<T>();
	Node<T>* Get(int index);
	void InsertHead(const T& Data);
	void InsertTail(const T& Data);
	void Insert(int index, const T& Data);
	int search(T Data);
	void RemoveHead();
	void RemoveTail();
	void Remove(int index);
	void Display();
	virtual bool isEmpty();
	virtual bool isFull();
	Iterator<T> begin() const;
	Iterator<T> end() const;
protected:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

/*
 * List class Constructor
 */
template<class T>
List<T>::List() :Node<T>()
{
	this->head = nullptr;
	this->tail = nullptr;
	size = 0;
}

/*
 * List class Destructor
 */
template<class T>
 List<T>::~List()
{
	 std::cout << "Clearing memory...\n\n";
}

/**
 *	Search list for an index, return its respective node
 */
template<class T>
Node<T>* List<T>::Get(int index)
{
	if (index < 0 || index > size)
		return 0;

	Node<T>* headNode = head;
	for (int i = 0; i < index; ++i)
	{
		headNode = headNode->Next;
	}

	return headNode;
}

/*
 *	Insert a Data value into the head node
 */
template<class T>
void List<T>::InsertHead(const T& Data)
{
	Node<T>* newNode = new Node<T>(Data);
	newNode->Next = head;

	if (head != nullptr)
	{
		head->Prev = newNode;
	}

	head = newNode;

	if (size == 0)
	{
		tail = head;
	}

	size++;
}

/*
 *	Insert a Data value into the tail node
 */
template<class T>
void List<T>::InsertTail(const T& Data)
{
	if (size == 0)
	{
		InsertHead(Data);
		return;
	}

	Node<T>* newNode = new Node<T>(Data);

	tail->Next = newNode;
	newNode->Prev = tail;

	tail = newNode;
	size++;
}

/*
 *	Insert a Data Value into any node
 */
template<class T>
void List<T>::Insert(int index, const T& Data)
{
	if (index < 0 || index > size)
	{
		return;
	}

	if (index == 0)
	{
		InsertHead(Data);
		return;
	}
	else if (index == size)
	{
		InsertTail(Data);
		return;
	}

	Node<T>* prevNode = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prevNode = prevNode->Next;
	}

	Node<T>* nextNode = prevNode->Next;
	Node<T>* newNode = new Node<T>(Data);

	newNode->Next = nextNode;
	newNode->Prev = prevNode;
	prevNode->Next = newNode;
	nextNode->Prev = newNode;
	size++;
}

/*
 * Search for a data value and return its index value
 */
template<class T>
int List<T>::search(T Data)
{
	if (size == 0)
	{
		return -1;
	}

	int index = 0;

	Node<T>* headNode = head;
	while (headNode->Data != Data)
	{
		index++;
		headNode = headNode->Next;

		if (headNode == nullptr)
		{
			return -1;
		}
	}

	return index;
}

/*
 *	Remove a Data value from the head node
 */
template<class T>
void List<T>::RemoveHead()
{
	if (size == 0)
	{
		return;
	}

	Node<T>* newNode = head;
	head = head->Next;

	delete newNode;

	if (head != nullptr)
	{
		head->Prev = nullptr;
	}

	size--;
}

/*
 *	Remove a Data value from the tail node
 */
template<class T>
void List<T>::RemoveTail()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		RemoveHead();
		return;
	}

	Node<T>* newNode = tail;
	tail = tail->Prev;
	tail->Next = nullptr;
	delete newNode;
	size--;
}

/*
 *	Remove a Data value from andy node
 */
template<class T>
void List<T>::Remove(int index)
{
	if (size == 0)
	{
		return;
	}

	if (index < 0 || index >= size)
	{
		return;
	}

	if (index == 0)
	{
		RemoveHead();
		return;
	}
	else if (index == size - 1)
	{
		RemoveTail();
		return;
	}

	Node<T>* prevNode = head;

	for (int i = 0; i < index - 1; ++i)
	{
		prevNode = prevNode->Next;
	}

	Node<T>* newNode = prevNode->Next;
	Node<T>* nextNode = newNode->Next;

	prevNode->Next = nextNode;
	nextNode->Prev = prevNode;

	delete newNode;
	size--;
}

/*
 *	Display the contents of the DLL
 */
template<class T>
void List<T>::Display()
{
	Node<T>* newNode = head;

	while (newNode != nullptr)
	{
		std::cout << newNode->Data << " -> ";
		newNode = newNode->Next;
	}


	std::cout << "NULL\n";
}

/*
 *	Check if the list is empty, return a boolean flag
 */
template<class T>
bool List<T>::isEmpty()
{
	return (size <= 0);
}

/*
 *	Check if the list is full, return a boolean flag
 */
template<class T>
bool List<T>::isFull()
{
	return (size > 0);
}

/*
 * Begin Iterator traversal
 */
template<class T>
Iterator<T> List<T>::begin() const
{
	return Iterator<T>(head->Next);
}

/*
 * End Iterator traversal
 */
template<class T>
Iterator<T> List<T>::end() const
{
	return Iterator<T>(tail);
}

template<class T>
T& Iterator<T>::operator*()
{
	return v->Data;
}

template<class T>
bool Iterator<T>::operator==(const Iterator& p) const
{
	return v == p->v;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator& p) const
{
	return v != p->v;
}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
	v = v->Next; return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator--()
{
	v = v->Prev; return *this;
}
