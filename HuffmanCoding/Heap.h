/**
 * @file Heap.h
 * 
 * @author Hamza Beder
*/

#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <vector>

class HeapNode {
public:
    /**
     * Instances of HeapNode store a character and its frequency in the file the user asks to compress.
     * 
    */
    HeapNode();
    HeapNode(char c, int freq);

    //Data each node needs to store
    char c;
    int freq;
    HeapNode * left;
    HeapNode * right;
};

class Heap{
public:

    /**
     * This class creates a Heap made up of HeapNodes.
    */
    Heap(int length);

    //Data associated with a Heap
    int length;
    int heap_size;
    HeapNode ** nodes;

    /**
     * Used to maintain the min-heap property.
    */
    void minHeapify(int idx);
};

#endif
