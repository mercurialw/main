#include "Trie.h"

void Trie::insert(const std::string& word) {
    TrieNode* currentNode = root;
    for (const char& c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            currentNode->children[c] = new TrieNode();
        }
        currentNode = currentNode->children[c];
    }
    currentNode->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* currentNode = root;
    for (const char& c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return currentNode->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* currentNode = root;
    for (const char& c : prefix) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return true;
}

bool Trie::removeHelper(TrieNode* node, const std::string& word, int index) {
    if (index == word.length()) {
        if (!node->isEndOfWord) { // �������� �� �������������
            return false; // ����� �� ���������� � Trie, ������ �������, ���������� false
        }
        node->isEndOfWord = false;
        return node->children.empty(); // ���� � �������� ���� ��� ������ �������� �����(empty), �� ����� ������� ���(���������� true)
    }

    char curChar = word[index];
    if (node->children.find(curChar) == node->children.end()) { // ���� ������� find ������� nullptr(end())
        return false; // ����� �� ���������� � Trie, ������ �������, ���������� false
    }

    TrieNode* nextNode = node->children[curChar];
    bool shouldRemoveNode = removeHelper(nextNode, word, index + 1); // ���������� ����������� ����� �� ������� ����

    if (shouldRemoveNode) {
        delete nextNode;
        node->children.erase(curChar); // ������� �������� ������� �� �����
    }

    return node->children.empty(); // ���� � �������� ���� ��� ������ �������� �����(empty), �� ����� ������� ���(���������� true)
}


void Trie::removeWordsWithEvenLengthHelper(TrieNode* node, int depth) {
    if (node == nullptr) {
        return;
    }

    // �������� ���� � ������ ����������� ������
    if (depth % 2 == 0) {
        node->isEndOfWord = false;
    }

    for (auto it = node->children.begin(); it != node->children.end();) {
        TrieNode* child = it->second;
        removeWordsWithEvenLengthHelper(child, depth + 1);

        if (child->children.empty() && !child->isEndOfWord) {
            delete child;
            it = node->children.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Trie::printHelper(TrieNode* node, const std::string& currentWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isEndOfWord) {
        std::cout << currentWord << std::endl;
    }

    for (const auto& elem : node->children) {
        char childChar = elem.first;
        TrieNode* childNode = elem.second;
        printHelper(childNode, currentWord + childChar);
    }
}