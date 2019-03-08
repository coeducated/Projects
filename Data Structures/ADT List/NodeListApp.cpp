#include "NodeList.h"
#include "Stack.h"
#include "Queue.h"
#include <stack>


int main()
{
	NodeList<int>* nl1 = new NodeList<int>;
	Stack<int>* s = new Stack<int>;
	Queue<int>* q = new Queue<int>;
	bool flag = true;
	int num;

	while (true)
	{
		std::cout << "Enter data value or -1 to quit.\n";
		std::cin >> num;
		if (num == -1)
		{
			break;
		}
		else
		{
			nl1->insert(num);
		}
	}

	std::cout << "\nRecursively Printed\n";
	nl1->reversePrintList();

	std::cout << "\nData sorted in ascending order.\n";
	nl1->printList();
	while (true)
	{
		std::cout << "Enter data value to delete or -1 to quit.\n";
		std::cin >> num;
		if (num == -1)
		{
			break;
		}
		else
		{
			nl1->deleteNode(num);
			nl1->printList();
		}
	}

	std::cout << "\nRemaining data.\n";
	nl1->printList();
	delete nl1;
	while (flag)
	{
		std::cout << "\n\n1. Push 2. Pop 3. Print 4. Show top 5.Queue an element 6. Dequeue 7. Quit\n";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case(1):
				std::cout << "Enter data value to push into stack: ";
				int n;
				std::cin >> n;
				s->push(n);
				break;
		case(2):
			s->pop();
			break;
		case(3):
			std::cout << "\nPrinting...\n\n";
			s->print();
			break;
		case(4):
			std::cout << "\nPeeking...\n";
			std::cout << s->Top();
			break;
		case(5):
			std::cout << "Enter data value to enqueue: ";
			int qn;
			std::cin >> qn;
			q->Enqueue(qn);
			std::cout << "Front of queue: " << q->first();
			break;
		case(6):
			std::cout << "Dequeuing...\n";
			q->Dequeue();
			std::cout << "New Front of queue: " << q->first();
			break;
		case(7):
			std::cout << "Quitting....\n";
			std::cout << "\nLast State of the stack:";
			s->print();
			return 1;
		default:
			std::cout << "Invalid...\n";
			break;
		}
	}
	delete s;

	
	
	system("pause");
	return 0;
}
