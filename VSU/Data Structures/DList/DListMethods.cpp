#include "Dlist.h"
#include <cmath>

Data::Data() {
	number = 0;
	balance = 0.0;
	fio.surname = "Иванов";
	fio.name = "Иван"; 
	fio.sec_name = "Иванович";
	adress.street = "неизвестна";
	adress.house_number = adress.appartment = 0;
}

Data::Data(std::string surname, std::string name, std::string sec_name,
	std::string street, int house_number, int appartment,
	long int _number, double _balance) {
	fio.surname = surname;
	fio.name = name;
	fio.sec_name = sec_name;
	adress.street = street;
	adress.house_number = house_number;
	adress.appartment = appartment;
	number = _number;
	balance = _balance;
}

std::ostream& operator<<(std::ostream& os, Data const& data) {
	return os << data.fio.surname << " " << data.fio.name
		<< " " << data.fio.sec_name << ", ул. " << data.adress.street
		<< ", д. " << data.adress.house_number << ", кв. " << data.adress.appartment
		<< ", номер телефона - " << data.number << ", баланс - "
		<< data.balance << std::endl;
}

Node::Node(Data _data) { 
	data.fio.surname = _data.fio.surname;
	data.fio.name = _data.fio.name;
	data.fio.sec_name = _data.fio.sec_name;
	data.adress.street = _data.adress.street;
	data.adress.house_number = _data.adress.house_number;
	data.adress.appartment = _data.adress.appartment;
	data.number = _data.number;
	data.balance = _data.balance;
	prev = next = NULL;
}

Node* Dlist::add_front(Data data) {
	Node* ptr = new Node(data);
	ptr->next = head;
	if (head != NULL)
		head->prev = ptr;
	if (tail == NULL)
		tail = ptr;
	head = ptr;

	return ptr;
}

Node* Dlist::add_back(Data data) {
	Node* ptr = new Node(data);
	ptr->prev = tail;
	if (tail != NULL)
		tail->next = ptr;
	if (head == NULL)
		head = ptr;
	tail = ptr;

	return ptr;
}

void Dlist::delete_front(){
	if (head == NULL) return;

	Node* ptr = head->next;
	if (ptr != NULL)
		ptr->prev = NULL;
	else
		tail = NULL;

	delete head;
	head = ptr;
}

void Dlist::delete_back() {
	if (tail == NULL) return;

	Node* ptr = tail->prev;
	if (ptr != NULL)
		ptr->next = NULL;
	else
		head = NULL;

	delete tail;
	tail = ptr;
}

Node* Dlist::get_by_key(int index) {
	Node* ptr = head;
	int n = 0;

	while (n != index) {
		if (ptr == NULL)
			return ptr;
		ptr = ptr->next;
		n++;
	}
	return ptr;
}

Node* Dlist::insert(int index, Data data) {
	Node* right = get_by_key(index);
	if (right == NULL)
		return add_back(data);
	
	Node* left = right->prev;
	if (left == NULL)
		return add_front(data);

	Node* ptr = new Node(data);
	ptr->prev = left;
	ptr->next = right;
	left->next = ptr;
	right->prev = ptr;
	
	return ptr;
}

void Dlist::erase(int index) {
	Node* ptr = get_by_key(index);
	if (ptr == NULL)
		return;

	if (ptr->prev == NULL) {
		delete_front();
		return;
	}

	if (ptr->next == NULL) {
		delete_back();
		return;
	}

	Node* left = ptr->prev;
	Node* right = ptr->next;
	left->next = right;
	right->prev = left;
	
	delete ptr;
}

void Dlist::print() {
	for (Node * ptr = head; ptr != NULL; ptr = ptr->next)
		std::cout << ptr->data;
	std::cout << std::endl;
}

void Dlist::erase(Node*& ptr) {
	if (ptr == NULL)
		return;

	if (ptr->prev == NULL) {
		delete_front();
		return;
	}

	if (ptr->next == NULL) {
		delete_back();
		return;
	}

	Node* left = ptr->prev;
	Node* right = ptr->next;
	left->next = right;
	right->prev = left;

	delete ptr;
}


void Dlist::sort() {
	int n = 0;
	Node* p = head;
	while (p) {
		n++;
		p = p->next;
	}

	for (int i = 0; i < n; ++i) {
		Node* current = head;
		Node* nextNode = head->next;

		for (int j = 0; j < n - 1 - i; ++j) {
			if (current->data.fio.surname > nextNode->data.fio.surname) {
				Data temp = current->data;
				current->data = nextNode->data;
				nextNode->data = temp;
			}

			current = nextNode;
			nextNode = nextNode->next;
		}
	}
}

void Dlist::delete_neg() {
	Node* ptr = head;
	while(ptr != NULL) {
		if (ptr->data.balance < 0) {
			Node* temp = ptr;
			ptr = ptr->next;
			erase(temp);
		}
		else 
			ptr = ptr->next;
	}
}