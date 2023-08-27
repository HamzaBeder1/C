//
// Created by Hamza Beder on 8/8/2023.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>
#include "Heap.h"

class PriorityQueue {
public:
    Heap * pq;
    PriorityQueue(int size);
    void insert(HeapNode * newNode);
    void createQueue(std::vector <char> chars, std::vector<int> freqs);
    HeapNode * extractMin();
    HeapNode * heapMin();
};


#endif //HUFFMANCODING_PRIORITYQUEUE_H
