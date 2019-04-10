#include <iostream>
#include <string>
#include "Node.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
std::string convertInfixToPostfix(std::string infix);
int evaluatePostfixExpression(std::string postfix);
int calculate(int a, int b, char operatorSign);
int operatorPrecedence(char ch);
int main()
{
	// Create infix expression
	std::string infixExpression, postfixExpression;
	int result;

	std::cout << "Enter an expression in the form '(A+(B^C)*D)/C'(No spaces): \n";
	std::cin >> infixExpression;

	postfixExpression = convertInfixToPostfix(infixExpression);

	// Eval and display
	std::cout << "Infix Expression: " << infixExpression << std::endl;
	std::cout << "Postfix Expression: " << postfixExpression << std::endl;
	result = evaluatePostfixExpression(postfixExpression);

	std::cout << "\nResult is: " << result << std::endl;
	system("pause");
	return 0;
}

std::string convertInfixToPostfix(std::string infix)
{
	// Creat new stack to store postfix expression
	std::string postfix = "";
	Stack<char> S1 = Stack<char>();
	char ch;

	for (int i = 0; infix[i]; i++)
	{
		ch = infix[i];

		if (ch == '(')
			S1.Push(ch);
		else if (ch == ')')
		{
			while (S1.s_size > 0 && S1.Top() != '(')
			{
				postfix = postfix + S1.Top();
				S1.Pop();
			}

			if (S1.s_size > 0 && S1.Top() == '(')
				S1.Pop();
		}

		else
		{
			int priority = operatorPrecedence(ch);

			if (priority == 0)
				postfix = postfix + ch;
			else
			{
				if (S1.s_size == 0)
					S1.Push(ch);
				else
				{
					while (S1.s_size > 0 && S1.Top() != '(' && priority <= operatorPrecedence(S1.Top()))
					{
						postfix = postfix + S1.Top();
						S1.Pop();
					}
					S1.Push(ch);
				}
			}
		}
	}
	while (S1.s_size > 0)
	{
		postfix += S1.Top();
		S1.Pop();
	}

	return postfix;
}

int evaluatePostfixExpression(std::string postfix)
{
	// Create new stack to store values
	Stack<int> S2 = Stack<int>();
	char ch;

	for (int i = 0; postfix[i]; i++)
	{
		ch = postfix[i];
		if (ch >= '0' && ch <= '9')
			S2.Push(ch-'0');
		else
		{
			int a, b;
			b = S2.Top();
			S2.Pop();

			a = S2.Top();
			S2.Pop();

			S2.Push(calculate(a, b, ch));
		}
	}

	return S2.Top();
}

int calculate(int a, int b, char operatorSign)
{
	if (operatorSign == '+')
		return a + b;
	else if (operatorSign == '-')
		return a - b;
	else if (operatorSign == '*')
		return a * b;
	else if (operatorSign == '/')
		return a / b;
	else if (operatorSign == '^')
		return pow(a, b);
}

int operatorPrecedence(char ch)
{
	if (ch == '^')
		return 3; //highest priority for exponential operator
	else if (ch == '/' || ch == '*')
		return 2; //high priority than + or - operator
	else if (ch == '+' || ch == '-')
		return 1; //lowest priority among operators
	else
		return 0; 
}
