/**
 * @file PriorityQueue.h
 * 
 * @author Hamza Beder
*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
#include "Heap.h"

class PriorityQueue {
public:
    
    PriorityQueue(int size);

    Heap * pq;

    /**
     * This method will inserts newNode into the priority queue while maintaining the min-heap property.
    */
    void insert(HeapNode * newNode);

    /**
     * This method will create the priority queue using the characters in the file and their frequencies.
    */
    void createQueue(std::vector <char> chars, std::vector<int> freqs);

    /**
     * This method will get the minimum value in the priority queue and ensure 
     * that the min-heap property is maintained afterwards.
    */
    HeapNode * extractMin();

    /**
     * This method will return the minimum valued node in the priorty queue without removing it.
    */
    HeapNode * queueMin();
};

#endif
