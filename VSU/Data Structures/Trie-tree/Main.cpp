#include "Trie.h"
using namespace std;

int main() {

	Trie trie;
	trie.insert("gas");
	trie.insert("swag");
	trie.insert("dry");
	trie.insert("dry");
	trie.insert("w");
	trie.insert("stakin");
	trie.print();
	trie.removeWordsWithEvenLength();
	cout << trie.search("stakin");
	return 0;
}