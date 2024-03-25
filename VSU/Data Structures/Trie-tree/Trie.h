#pragma once
#include <iostream>
#include <map>

class TrieNode {
public:
    std::map <char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() { isEndOfWord = false; }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(const std::string& word);

    bool search(const std::string& word);

    bool startsWith(const std::string& prefix);

    void remove(const std::string& word) { removeHelper(root, word, 0); }

    void removeWordsWithEvenLength() { removeWordsWithEvenLengthHelper(root, 0); }

    void print() { printHelper(root, ""); }

private:
    bool removeHelper(TrieNode* node, const std::string& word, int index);
    void removeWordsWithEvenLengthHelper(TrieNode* node, int depth);
    void printHelper(TrieNode* node, const std::string& currentWord);
};