//
// Created by Kareem Rashed on 12/11/2024.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include "PriorityQueue.h"
using namespace std;

class Huffman {
private:
    string fileName;


    int padding;
    int chars;
    Node<char>* root;
    PriorityQueue<char> pq;
    unordered_map<char, vector<bool>> Encodings;


public:
    Huffman(string file);
    ~Huffman();
    void Frequencies(string file);
    void buildHuffmanTree();
    void CreateEncodings(Node<char>* temproot, string enc);
    void Compress(string type);
    void Decompress(string type);
    void EncodeTreeNormal(string file);
    void EncodeTreeCaeser(string file);

    void ReadTreeNormal(string file);
    void ReadTreeCaeser(string file);







};



#endif //HUFFMAN_H
