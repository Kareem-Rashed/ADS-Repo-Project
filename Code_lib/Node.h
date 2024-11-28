//
// Created by Kareem Rashed on 10/11/2024.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class Node {

public:

    T data;
    int priori;
    Node *next;
    Node *right;
    Node *left;



    Node(const T& data, int priority ): data(data), priori(priority), next(nullptr), right(nullptr), left(nullptr) {}
    T getData() const;
    int getPriority() const;
};





#endif //NODE_H
