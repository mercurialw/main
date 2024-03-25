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
        if (!node->isEndOfWord) { // Проверка на существование
            return false; // Слово не существует в Trie, нечего удалять, возвращаем false
        }
        node->isEndOfWord = false;
        return node->children.empty(); // Если у текущего узла нет других дочерних узлов(empty), то можно удалить его(возвращаем true)
    }

    char curChar = word[index];
    if (node->children.find(curChar) == node->children.end()) { // Если функция find вернула nullptr(end())
        return false; // Слово не существует в Trie, нечего удалять, возвращаем false
    }

    TrieNode* nextNode = node->children[curChar];
    bool shouldRemoveNode = removeHelper(nextNode, word, index + 1); // Рекурсивно запрашиваем нужно ли удалить узел

    if (shouldRemoveNode) {
        delete nextNode;
        node->children.erase(curChar); // Удаляем ненужный словарь по ключу
    }

    return node->children.empty(); // Если у текущего узла нет других дочерних узлов(empty), то можно удалить его(возвращаем true)
}


void Trie::removeWordsWithEvenLengthHelper(TrieNode* node, int depth) {
    if (node == nullptr) {
        return;
    }

    // Удаление слов с четным количеством знаков
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