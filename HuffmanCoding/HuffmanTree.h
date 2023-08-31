/**
 * @file HuffmanTree.h
 * 
 * @author Hamza Beder
*/

#ifndef HUFFMANCODING_HUFFMANTREE_H
#define HUFFMANCODING_HUFFMANTREE_H

#include <map>
#include <vector>
#include <fstream>
#include "Heap.h"
#include "PriorityQueue.h"

class HuffmanTree{
public:
    /**
    * This class will build a HuffmanTree using a priority queue, and the constructed tree will be used
    * to compress and decompress a file.
    */

    HeapNode * root; //This is the root of the Huffman Tree.
    std::map<char, std::string> HuffmanCodes;   //This maps characters in the file to Huffman codes, used for compressing.
    std::map<std::string, char> decompressingMap; //This maps Huffman codes to characters in the file, used for decompressing.

    /**
     * This method will store the characters and their associated frequencies in the vectors chars and freqs
    */
    void countFrequency(std::vector<char> &chars, std::vector<int> &freqs, std::string path); 
    
    /**
     * This method constructs the Huffman Tree
    */
    void createTree(std::vector <char> chars, std::vector<int> freqs, std:: string path);

    /**
     * This method will traverse the Huffman Tree to map codes<->characters
    */
    void getCodes(HeapNode * currNode, std::string code);

    /**
     * This method is used to compress a file.
    */
    void compress(std::string path);

    /**
     * This method is used to decompress a file
    */
    void decompress();
};

#endif
