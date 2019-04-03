#include <iostream>
#include <string>
#include "Node.h"
#include "List.h"
#include "Stack.h"

int main()
{
	// Create DLL of Integers
	List<int> DoublyLinkedList = List<int>();
	// Create DLL of Characters
	List<char> DoublyLinkedList2 = List<char>();
	// Create DLL of Strings
	List<std::string> DoublyLinkedList3 = List<std::string>();


	// Add Integers
	DoublyLinkedList.InsertHead(43);
	DoublyLinkedList.InsertHead(76);
	DoublyLinkedList.InsertTail(15);
	DoublyLinkedList.InsertTail(44);
	DoublyLinkedList.InsertHead(100);




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
	std::cout << "From left to right(Head --> Tail)\n\n";
	std::cout << "List of Integers:\n";
	DoublyLinkedList.Display();
	std::cout << "List of Characters:\n";
	DoublyLinkedList2.Display();
	std::cout << "List of Strings:\n";
	DoublyLinkedList3.Display();
	std::cout << std::endl << std::endl;

	// Get a value
	std::cout << "Get value of the third index: \n";
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
	std::cout << "List of Integers(After Removal):\n";
	DoublyLinkedList.Display();
	std::cout << "List of Characters(After Removal):\n";
	DoublyLinkedList2.Display();
	std::cout << "List of Strings(After Removal):\n";
	DoublyLinkedList3.Display();
	std::cout << std::endl << std::endl;

	return 0;
}
