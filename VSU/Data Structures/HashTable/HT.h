#pragma once
#include <iostream>

template<class T>
class HT {

    int size;
    const int c = 1;
    struct Block {
        enum Status { FREE, RESERVED, DELETED } status;
        T value;
    } *blocks;

    int blockCounter = 0;

public:


    HT(int size) : size(size), blocks(new Block[size]) {
        for (int i = 0; i < size; ++i) {
            blocks[i].status = Block::FREE;
        }
    }


    ~HT() { delete[] blocks; }

    void insert(T const& value) {
        int index = getHash(value);
        int firstIndex = index;
        int i = 1;
        while (blocks[index].status == Block::RESERVED) {
            index = (firstIndex + c * i * i) % size;
            ++i;
        }
        blocks[index].value = value;
        blocks[index].status = Block::RESERVED;
        ++blockCounter;

        if ((double)blockCounter > 0.7 * size)
            doubleSize();
    }

    bool search(T const& value) {
        int index = getHash(value);
        int firstIndex = index;
        int i = 1;
        while (blocks[index].status != Block::FREE) {
            if (blocks[index].status == Block::RESERVED && blocks[index].value == value)
                return true;
            index = (firstIndex + c * i * i) % size;
            ++i;
        }
        return false;
    }

    void remove(T const& value) {
        int index = getHash(value);
        int originalIndex = index;
        int i = 1;
        while (blocks[index].status != Block::FREE) {
            if (blocks[index].status == Block::RESERVED && blocks[index].value == value) {
                blocks[index].status = Block::DELETED;
                --blockCounter;
                return;
            }
            index = (originalIndex + c * i * i) % size;
            ++i;
        }
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            if (blocks[i].status == Block::RESERVED) {
                std::cout << "Hash code - " << getHash(blocks[i].value) << ", value - " << blocks[i].value << " " << i << std::endl;
            }
        }
    }

    int getSize() { return size; }

private:

    int getHash(T const& value) {
        int hash = 0;
        for (char c : value) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

    void doubleSize() {
        int newSize = size * 2;
        Block* newBlocks = new Block[newSize];
        for (int i = 0; i < newSize; ++i) {
            newBlocks[i].status = Block::FREE;
        }

        for (int i = 0; i < size; ++i) {
            if (blocks[i].status == Block::RESERVED) {
                int newIndex = getHash(blocks[i].value);
                int firstIndex = newIndex;
                int j = 1;
                while (newBlocks[newIndex].status == Block::RESERVED) {
                    newIndex = (firstIndex + c * j * j) % newSize;
                    ++j;
                }
                newBlocks[newIndex].value = blocks[i].value;
                newBlocks[newIndex].status = Block::RESERVED;
            }
        }

        delete[] blocks;
        blocks = newBlocks;
        size = newSize;
    }
};