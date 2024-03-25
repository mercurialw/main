#include <iostream>

struct Data {
	struct FIO {
		std::string surname, name, sec_name;
	} fio;
	struct Adress {
		std::string street;
		int house_number, appartment;
	} adress;
	long int number;
	double balance;

	Data();
	Data(std::string, std::string, std::string, std::string, 
		int, int, long int, double);

	friend std::ostream& operator<<(std::ostream& os, Data const& data);
};

class Node {
public:
	Data data;
	Node* prev, * next;
	
	Node(Data data);
};

class Dlist {
public:
	Node* head, * tail;

	Dlist() : head(NULL), tail(NULL) {}
	~Dlist() { while (head != NULL) delete_front(); }

	Node* add_front(Data data);
	Node* add_back(Data data);
	void delete_front();
	void delete_back();
	Node* get_by_key(int key);
	Node* operator[](int index) { return get_by_key(index); }
	Node* insert(int index, Data data);
	void erase(int index);
	void print();
	void erase(Node*& ptr);
	void sort();
	void delete_neg();
};