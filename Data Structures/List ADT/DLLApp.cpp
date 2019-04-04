#include <iostream>
#include <string>
#include "Node.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	// Create DLL of Integers
	List<int> DoublyLinkedList = List<int>();
	// Create DLL of Characters
	List<char> DoublyLinkedList2 = List<char>();
	// Create DLL of Strings
	List<std::string> DoublyLinkedList3 = List<std::string>();
	// Create Stack of Integers
	Stack<int> stackList = Stack<int>();
	// Create a Queue of Integers
	Queue<int> queueList = Queue<int>();

	// Add Integers
	DoublyLinkedList.InsertHead(43);
	DoublyLinkedList.InsertHead(76);
	DoublyLinkedList.InsertTail(15);
	DoublyLinkedList.InsertTail(44);
	DoublyLinkedList.InsertHead(100);

	// Add Integers onto the stack
	stackList.Push(50);
	stackList.Push(10);
	stackList.Push(20);
	stackList.Push(30);

	// Add Integers into the queue
	queueList.Enqueue(1);
	queueList.Enqueue(2);
	queueList.Enqueue(3);
	queueList.Enqueue(4);


	// Add Characters
	DoublyLinkedList2.InsertHead('a');
	DoublyLinkedList2.InsertHead('b');
	DoublyLinkedList2.InsertTail('c');


	// Add Strings
	DoublyLinkedList3.InsertHead("Ally");
	DoublyLinkedList3.InsertHead("Alyssa");
	DoublyLinkedList3.InsertTail("Meghan");
	DoublyLinkedList3.InsertHead("Savannah");
	DoublyLinkedList3.InsertTail("Jenna");

	// Display Data before removal
	std::cout << "From left to right(Head --> Tail) / (Fist --> Last)\n\n";
	std::cout << "---List of Integers---\n";
	DoublyLinkedList.Display();
	std::cout << "---List of Characters---\n";
	DoublyLinkedList2.Display();
	std::cout << "---List of Strings---\n";
	DoublyLinkedList3.Display();
	std::cout << std::endl << std::endl;
	
	// Display Stack State
	std::cout << "---Stack---\n";
	stackList.DisplayStack();

	// Show the top
	std::cout << "\nPeeking...\n";
	std::cout << stackList.Top();
	std::cout << std::endl;

	// Pop the top
	std::cout << "\n---Removing---\n";
	stackList.Pop();
	
	std::cout << "---Stack---\n";
	// Display after top popped
	stackList.DisplayStack();

	// Display Queue
	std::cout << "\n---Queue---\n";
	while (!queueList.isQEmpty())
	{
		std::cout << queueList.Front() << " - ";
		queueList.Dequeue();
	}
	std::cout << "NULL" << std::endl;
	// Get a value
	std::cout << "\nGet value of the third index: \n";
	Node<int>* Get = DoublyLinkedList.Get(3);
	if (Get != NULL)
		std::cout << Get->Data;
	else
		std::cout << "Not found...\n";

	std::cout << std::endl;
	std::cout << "Get the value of the second index of the 2nd List: \n";
	Node<char>* Get2 = DoublyLinkedList2.Get(2);
	if (Get2 != NULL)
		std::cout << Get2->Data;
	else
		std::cout << "Not found...\n\n";
	std::cout << std::endl;

	// Search for a value
	std::cout << "The position of value 43:\n";
	int srch = DoublyLinkedList.search(43);
	std::cout << srch << std::endl << std::endl;
	std::cout << "The position of value 'Alyssa':\n";
	int srchString = DoublyLinkedList3.search("Alyssa");
	std::cout << srchString << std::endl << std::endl;


	//Remove a value
	std::cout << "Removing the first element of the 1st DLL... \n";
	DoublyLinkedList.Remove(0);
	std::cout << std::endl;
	std::cout << "Removing the 2nd element of the 2nd DLL...\n";
	DoublyLinkedList2.Remove(1);
	std::cout << std::endl;
	std::cout << "Removing the 3rd element of the 3rd DLL...\n";
	DoublyLinkedList3.Remove(2);
	std::cout << std::endl;

	// Display Data after removal
	std::cout << "From left to right(Head --> Tail)\n\n";
	std::cout << "---Final state of the Integer List---\n";
	DoublyLinkedList.Display();
	std::cout << "--Final state of the Character List---\n";
	DoublyLinkedList2.Display();
	std::cout << "---Final state of the String List---\n";
	DoublyLinkedList3.Display();
	std::cout << "---Final state of the Stack---\n";
	stackList.DisplayStack();
	std::cout << std::endl;


	return 0;
}
