#include <iostream>

class Stack {

	struct Node {
		int data;
		Node* next;
		Node(int data) : data(data), next(NULL) {}
	};
	Node * top;

public:

	Stack();
	~Stack();

	void push(int);
	void pop();
	int peak();
	bool isEmpty();
	void clear();
};

int evalPostfixExpression(std::string const&);