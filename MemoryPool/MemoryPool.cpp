/**
 * @file MemoryPool.cpp
 * 
 * @brief This project is used to allocate a block of memory to be used, and then to deallocate once done.
 * 
 * @author Hamza Beder
*/

#include "MemoryPool.h"

/**
 * This is the constructor for the BlockHeader() class. 
 * 
 * It initializes all instances to be free.
*/
BlockHeader :: BlockHeader(){
    isFree = true;
}

/**
 * This is the constructor for the MemoryPool() class. 
 * 
 * It initializes the size of the pool and uses that size to allocate the appropriate amount of memory. The
 * usedSize, firstBlock, and lastBlock are initialized.
 * 
 * @param size_t poolSize This is the size of the pool, meaning the amount of memory that will be allocated from the OS.
*/
MemoryPool :: MemoryPool(size_t poolSize){
    this->poolSize = poolSize;
    this->usedSize = 0;
    this->pool = (void*) malloc(poolSize);
    firstBlock = lastBlock = nullptr;
}

/**
 * This method is for allocating memory from the memory block when the user requests it.
 * 
 * @param size This is how much memory the user requested.
*/
void * MemoryPool :: allocate(size_t size){

    //if there is not enough memory, catch block will print an error, and nullptr is returned.
    try{
        if(this->poolSize - this->usedSize < size + sizeof(BlockHeader))
            throw(-1);
    }
    catch(int num){
        cout << "No memory available";
        return nullptr;
    }

    //The location the newBlock points to will be determined by the start location of the pool and the usedSize
    BlockHeader * newBlock = reinterpret_cast<BlockHeader*>(reinterpret_cast<char*>(pool) + usedSize);
    this->usedSize += size + sizeof(BlockHeader);

    //initializes the new block.
    newBlock->size = size;
    newBlock->isFree = false;
    newBlock->data = reinterpret_cast<char*>(newBlock) + sizeof(BlockHeader);

    //place the new BlockHeader into the linked list.
    if(firstBlock == nullptr){
        firstBlock = lastBlock = newBlock;
        firstBlock->next = firstBlock->prev = nullptr;
    }
    else{
        newBlock ->prev = lastBlock;
        newBlock->next = nullptr;
        lastBlock ->next = newBlock;
        lastBlock = lastBlock->next;
    }

    return newBlock->data;
}

void MemoryPool :: deallocate(void * data){
    //A pointer to the header needs to be determined to get data's information, and this line stores it in header.
    BlockHeader * header = reinterpret_cast<BlockHeader*>(reinterpret_cast<char*>(data) - sizeof(BlockHeader));

    //Removes the BlockHeader from the linked list.
    this->usedSize -= (header->size + sizeof(BlockHeader));
    header->isFree= true;
    if(header == firstBlock){
        firstBlock = header->next;
    }
    else{
        header->prev->next = header->next;
    }
}

