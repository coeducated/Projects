#pragma once
#include "Node.h"
#include "List.h"

template <class T>
class Stack : public List<T>
{
private:
	int s_size;
	Node<T>* s_top;
public:
	Stack<T>();
	~Stack<T>();
	T Top();
	void Push(const T& val);
	void Pop();
	void DisplayStack();
};

template<class T>
Stack<T>::Stack()
{
	this->s_top = nullptr;
	s_size = 0;
}

template<class T>
Stack<T>::~Stack()
{
	std::cout << "Deleting stack...\n";
}

template<class T>
T Stack<T>::Top()
{
	return s_top->Data;
}

template<class T>
void Stack<T>::Push(const T& val)
{
	if (s_top == nullptr)
	{
		s_top = new Node<T>;
		s_top->Next = nullptr;
		s_top->Data = val;
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->Data = val;
		temp->Next = s_top;
		s_top = temp;
	}
}

template<class T>
void Stack<T>::Pop()
{
	if (s_top == nullptr)
	{
		std::cout << "Stack is empty. \n";
			return;
	}
	else
	{
		std::cout << s_top->Data << " is Popped\n\n";
		Node<T>* temp = s_top;
		s_top = s_top->Next;
		delete temp;
	}
}

template<class T>
void Stack<T>::DisplayStack()
{
	Node<T>* temp = s_top;
	while (temp != nullptr)
	{
		std::cout << temp->Data << " ";
		temp = temp->Next;
	}
	std::cout << std::endl;
}
