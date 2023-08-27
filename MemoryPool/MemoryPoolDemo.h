
#ifndef MEMORYPOOLDEMO_H
#define MEMORYPOOLDEMO_H

#include <iostream>
using namespace std;

class BlockHeader{
public:
    size_t size;
    bool isFree;
    void * data;
    BlockHeader* prev;
    BlockHeader * next;
    BlockHeader();
};

class MemoryPoolDemo {
public:
    size_t poolSize;
    size_t usedSize;
    void * pool;
    BlockHeader* firstBlock;
    BlockHeader* lastBlock;
    MemoryPoolDemo(size_t poolSize);
    void* allocate(size_t size);
    void deallocate(void * data);
};
