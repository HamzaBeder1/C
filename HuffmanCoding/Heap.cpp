/**
 * @file Heap.cpp
 * 
 * @brief This is the Heap that will be used to implement a Priority Queue.
 * 
 * @author Hamza Beder
*/

#include "Heap.h"
using namespace std;

/**
 * Constructor for a HeapNode
*/
HeapNode:: HeapNode(){
        this->c = 0;
        this->freq = 0;
        this->left = this->right = nullptr;
}

/**
 * Constructor for a HeapNode
 * @param c This is the character in the file associated with the node
 * @param freq This is the frequency of c
*/

HeapNode:: HeapNode(char c, int freq){
        this->c = c;
        this->freq = freq;
        this->left = this->right = nullptr;
}

/**
 * Constructor for a Heap
 * @param length This is the maximum capacity of the Heap.
*/
Heap:: Heap(int length){
    this->length = length;
    this->heap_size = 0;
    this->nodes = new HeapNode*[length];
}

/**
 * This is a recursive function that maintains the min-heap property.
 * @param idx Index of the node that will be checked in the current iteration.
*/
void Heap:: minHeapify(int idx){
    int smallest = idx;
    if(2*idx+1 < this->heap_size && this->nodes[2*idx+1]->freq < this->nodes[smallest]->freq)
        smallest = 2*idx+1;
    if(2*idx+2 < this->heap_size && this->nodes[2*idx+2]->freq < this->nodes[smallest]->freq)
        smallest = 2*idx+2;
    if(smallest != idx){
        HeapNode * temp = this->nodes[smallest];
        this->nodes[smallest] = this->nodes[idx];
        this->nodes[idx] = temp;
        minHeapify(smallest);
    }
}
