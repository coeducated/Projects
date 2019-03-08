#pragma once
#include "Node.h"

template <class T>
class NodeList : public Node<T>
{
public:
	NodeList<T>();
	~NodeList<T>();
	void addToHead(const T& data);
	void printList();
	void insert(const T& data);
	void deleteNode(const T& data);
	void reversePrintList();

private:
	Node<T>* head;
	int size;
	void reversePrintWorker(Node<T>*);
};

template <class T>
NodeList<T>::NodeList() :Node<T>()
{
	size = NULL;
	this->head = nullptr;
	this->next = nullptr;
}

template<class T>
NodeList<T>::~NodeList()
{
	std::cout << "Clearing mem...\n\n";
}

template <class T>
void NodeList<T>::addToHead(const T& data)
{
	Node<T>* newOne = new Node<T>(data);

	if (head == nullptr)
	{
		head = newOne;
	}
	else
	{
		newOne->next = head;
		head = newOne;
	}

	size++;
}

template <class T>
void NodeList<T>::printList()
{
	Node<T>* tp = head;

	while(tp != nullptr)
	{
		std::cout << *tp << std::endl;
		tp = tp->next;
	}
}

template <class T>
void NodeList<T>::insert(const T& data)
{
	Node<T>* newNode = new Node<T>(data);

	// Case 1 - empty list
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node<T>* curr = head;
		Node<T>* trail = nullptr;

		// Traverse
		while (curr != nullptr)
		{
			if (curr->data >= newNode->data)
			{
				break;
			}
			else
			{
				trail = curr;
				curr = curr->next;
			}
		}
		// Case 2 - insert at head ( not empty )
		if (curr == head)
		{
			newNode->next = head;
			head = newNode;
		}
		// Case 3 - insert after head ( not empty )
		else
		{
			newNode->next = curr;
			trail->next = newNode;
		}
	}
	size++;
}

template <class T>
void NodeList<T>::deleteNode(const T& data)
{
	if (head == nullptr)
	{
		std::cout << "Node cannot be deleted from empty list.\n";
	}
	else
	{
		Node<T>* curr = head;
		Node<T>* trail = nullptr;

		while (curr != nullptr)
		{
			if (curr->data == data)
			{
				break;
			}
			else
			{
				trail = curr;
				curr = curr->next;
			}
		}
		if (curr == nullptr)
		{
			std::cout << "Data value: " << data << " not found\n";
		}
		else
		{
			if (head == curr)
			{
				head = head->next;
			}
			else
			{
				trail->next = curr->next;
			}
			delete curr;
			size--;
		}
	}
}

template <class T>
void NodeList<T>::reversePrintList()
{
	reversePrintWorker(head);
}

template <class T>
void NodeList<T>::reversePrintWorker(Node<T>* curr)
{
	if (curr != nullptr)
	{
		reversePrintWorker(curr->next);
		std::cout << *curr << std::endl;
	}
}
