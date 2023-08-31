/**
 * @file PriorityQueue.h
 * 
 * @brief This is the priority queue that is used to build the Huffman Tree.
 * @author Hamza Beder
*/

#include "PriorityQueue.h"
using namespace std;

/**
 * This is the constructor for the priority queue.
 * @param size This is used to create a Heap of the size specified.
*/
PriorityQueue ::PriorityQueue(int size) {
    pq = new Heap(size);
}

/**
 * This inserts a new node into the priority queue.
 * 
 * The new node is inserted as the last node in the priority queue. It then floats up
 * to its appropriate position, meaning its parent has a smaller frequency than it.
 * 
 * @param newNode the new HeapNode to be added to the priority queue.
*/
void PriorityQueue:: insert(HeapNode * newNode){
    pq->heap_size++;
    int i = pq->heap_size-1;
    pq->nodes[i] = newNode;
    while(i >= 0 && pq->nodes[i]->freq < pq->nodes[(i-1)/2]->freq){
        HeapNode * temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[(i-1)/2];
        pq->nodes[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

/**
 * This creates the priority queue.
 * 
 * It uses the insert method to insert as many nodes as there are characters in the file.
 * 
 * @param chars This is the array of characters found in the file.
 * @param freqs This is an array storing the frequency of each character in the file.
*/
void PriorityQueue::createQueue(vector<char> chars, vector<int> freqs) {
    for(int i = 0; i < this->pq->length; i++){
        HeapNode * newNode = new HeapNode(chars[i], freqs[i]);
        this->insert(newNode);
    }
}

/**
 * Extracts the minimum valued node from the priority queue, meaning the node with
 * the smallest frequency.
*/
HeapNode * PriorityQueue:: extractMin(){
    HeapNode* head = this->queueMin();
    this->pq->nodes[0] = this->pq->nodes[this->pq->heap_size-1];
    this->pq->heap_size--;
    this->pq->minHeapify(0);
    return head;
}

/**
 * This returns the minimum from the priority queue.
*/
HeapNode * PriorityQueue:: queueMin(){
    return this->pq->nodes[0];
}
