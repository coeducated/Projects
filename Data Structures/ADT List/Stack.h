#pragma once
#include "Node.h"


template <class T>
class Stack : public Node<T>
{
private:
	Node<T>* top;
public:
	Stack<T>();
	~Stack<T>();
	bool isEmpty();
	T Top() {
		if (top)
			return top->data;
		else std::cout << "Stack is empty" << std::endl;
	}
	void push(const T& val);
	void pop();
	void print();
};

template<class T>
Stack<T>::Stack()
{
	top = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
	std::cout << "\nClearing mem...\n";
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (top == nullptr)
		return false;
	else
		return true;
}

template<class T>
void Stack<T>::push(const T& val)
{
	if (top == nullptr)
	{
		top = new Node<T>;
		top->next = nullptr;
		top->data = val;
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = top;
		top = temp;
	}
}

template<class T>
void Stack<T>::pop()
{
	if (top == nullptr)
	{
		std::cout << "Stack is empty.\n";
		return;
	}
	else
	{
		std::cout << top->data << " is popped\n";
		Node<T>* temp = top;
		top = top->next;
		delete temp;
	}
}

template<class T>
void Stack<T>::print()
{
	Node<T>* temp = top;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
