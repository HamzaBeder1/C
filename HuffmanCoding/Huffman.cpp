/**
 * @file HuffmanTree.cpp
 * 
 * @brief This class performs file compression and decompression using a Huffman Tree
 * 
 * @author Hamza Beder
*/

#include "HuffmanTree.h"
#include <fstream>
using namespace std;

/**
 * This function will read a file and store the characters found along with how often they appear.
 * @param chars stores the characters found in the file.
 * @param freqs stores the frequency of characters.
 * @param path The path to the file to be decompressed.
*/
void HuffmanTree:: countFrequency(vector<char> &chars, vector<int> &freqs, string path){
    vector <vector<int>> result;
    vector <int> freqTemp(256,0);
    vector <int> charTemp(256,0);
    ifstream fin;
    fin.open(path);
    char c;
    while(fin.get(c))
    {
        charTemp[c] = 1;
        freqTemp[c]++;
    }

    for(int i = 0; i<256; i++){
        if(charTemp[i] == 1){
            chars.push_back(i);
            freqs.push_back(freqTemp[i]);
        }
    }
}

/**
 * This method creates the Huffman Tree.
 * 
 * A priority queue is created using the characters in the file and their associated frequencies.
 * Then, until a single node remains in the queue, two nodes are popped at a time, a new node is created
 * with a frequency of the sum of the two popped node's frequencies, the node's children are set to the two extracted
 * nodes, and then this new node is inserted into the queue.
 * 
 * @param chars This is the array of characters in the file.
 * @param freqs This stores the frequency of characters.
 * @param path The path to the file to be compressed and decompressed.
 * 
*/
void HuffmanTree:: createTree(vector<char> chars, vector<int> freqs, string path){
    countFrequency(chars, freqs, path);
    PriorityQueue *pq = new PriorityQueue(chars.size());
    pq->createQueue(chars,freqs);
    while(pq->pq->heap_size > 1){
        HeapNode * node1 = pq->extractMin();
        HeapNode* node2 = pq->extractMin();
        HeapNode * newNode = new HeapNode(0, node1->freq+node2->freq);
        newNode->left = node1;
        newNode->right = node2;
        pq->insert(newNode);
    }
    this->root = pq->extractMin();
}

/**
 * This traverses the Huffman Tree using recursion. 
 * 
 * Once a leaf node is reached, the hashmaps HuffmanCodes and decompressingMap are updated
 * to map characters to codes and vice-versa.
 * 
 * @param currNode Current node in the traversal of the tree.
 * @param code This maintians the code associated with the current branch in the tree.
*/
void HuffmanTree::getCodes(HeapNode * currNode, string code) {
    if(currNode->left == nullptr && currNode->right == nullptr)
    {
        this->HuffmanCodes[currNode->c] = code;
        this->decompressingMap[code] = currNode->c;
    }
    else{
        if(currNode->left)
                getCodes(currNode->left, code+"0");
            if(currNode->right)
                getCodes(currNode->right, code+"1");
        }
}

/**
 * This compresses a file using the Huffman Codes obtained by traversing the Huffman Tree.
 * @param path The path of the file to be compressed.
*/

void HuffmanTree::compress(string path){
    vector<char> chars;
    vector <int> freqs;
    createTree(chars, freqs, path);
    this->getCodes(root, "");
    ifstream fin;
    ofstream fout;
    fout.open("compressed.txt");
    fin.open(path);
    char c;
    while(fin.get(c)){
        fout << this->HuffmanCodes[c];
    }
}

/**
 * This method decompresses the file.
 * 
 * It traverses the tree until a root node is reached, storing the code associated with the 
 * branch it is traversing using DFS.
 * 
 * The HashMap decompressingMap is used to obtain the character with the obtained code.
*/
void HuffmanTree::decompress(){
    ifstream fin;
    ofstream fout;
    fin.open("C:\\Users\\Hamza Beder\\Documents\\MyProjects\\huffmanCoding\\compressed.txt");
    fout.open("decompressed.txt");
    char c;
    string code = "";
    HeapNode * temp = this->root;
    while(fin.get(c)){
            if(c == '0'){
                code+="0";
                temp = temp->left;
            }
            else if(c == '1'){
                code+="1";
                temp = temp->right;
            }
        if(temp->left == nullptr && temp->right == nullptr){
            fout << decompressingMap[code];
            temp = this->root;
            code = "";
        }
        }
    }
