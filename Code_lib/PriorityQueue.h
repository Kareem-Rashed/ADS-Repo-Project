//
// Created by Kareem Rashed on 10/11/2024.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class PriorityQueue
{
public:


    Node<T> *root;
    int size;
    public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);

    ~PriorityQueue();
    void insert(const T& data, int priori);
    void insert(Node<T>* inNode);
    int getSize();
    bool isEmpty();

    Node<T> *dequeue();
    void display();


};



#endif //PRIORITYQUEUE_H
