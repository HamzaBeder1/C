#include "MemoryPoolDemo.h"

BlockHeader :: BlockHeader(){
    isFree = true;
}

MemoryPoolDemo :: MemoryPoolDemo(size_t poolSize){
    this->poolSize = poolSize;
    this->usedSize = 0;
    this->pool = (void*) malloc(poolSize);
    firstBlock = lastBlock = nullptr;
}

void * MemoryPoolDemo :: allocate(size_t size){
    if(this->poolSize - this->usedSize < size + sizeof(BlockHeader))
        return nullptr;



    BlockHeader * newBlock = reinterpret_cast<BlockHeader*>(reinterpret_cast<char*>(pool) + usedSize);
    this->usedSize += size + sizeof(BlockHeader);

    newBlock->size = size;
    newBlock->isFree = false;
    newBlock->data = reinterpret_cast<char*>(newBlock) + sizeof(BlockHeader);

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

void MemoryPoolDemo :: deallocate(void * data){
    BlockHeader * header = reinterpret_cast<BlockHeader*>(reinterpret_cast<char*>(data) - sizeof(BlockHeader));
    this->usedSize -= (header->size + sizeof(BlockHeader));
    header->isFree= true;
    if(header == firstBlock){
        firstBlock = header->next;
    }
    else{
        header->prev->next = header->next;
    }
}
