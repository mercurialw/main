#include "HT.h"
#include <string>

using namespace std;

int main() {

	HT<string> ht(5);
	ht.insert("apple");
	ht.insert("57");
	ht.insert("banana");
	ht.insert("57");
	ht.print();
	ht.remove("apple");
	cout << ht.getSize() << endl;
	ht.insert("10");
	ht.print();
	cout << ht.getSize() << endl;
	return 0;
}