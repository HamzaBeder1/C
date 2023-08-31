/**
 * @file MemoryPool.h
 * 
 * @author Hamza Beder
*/

#ifndef MEMORYPOOL_H
#define MEMORYPOOL_H
#include <iostream>
using namespace std;

class BlockHeader{
public:
    /**
    * This class, BlockHeader, is for storing information about each chunk of the memory block that has been allocated
    */
    BlockHeader();

    //Data to be stored
    size_t size;
    bool isFree;
    void * data;
    BlockHeader* prev;
    BlockHeader * next;
};

class MemoryPool {
public:
    /**
     * This class implements the MemoryPool. It is used for allocating the memory from the OS and controlling requests for memory from users.
    */
    MemoryPool(size_t poolSize);

    //Data members storing information about the MemoryPool.
    size_t poolSize;
    size_t usedSize;
    void * pool;
    BlockHeader* firstBlock;
    BlockHeader* lastBlock;

    /**
     * Used for allocating memory from the memory block.
     * @param size This is the amount of memory that was requested.
    */
    void* allocate(size_t size);

    /**
     * Used for deallocating memory from the memory block.
     * @param data This is a pointer to the data that needs to be deallocated.
    */
    void deallocate(void * data);
};
#endif
