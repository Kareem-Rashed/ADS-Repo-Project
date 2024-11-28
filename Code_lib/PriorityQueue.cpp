//
// Created by Kareem Rashed on 10/11/2024.
//

#include "PriorityQueue.h"
#include <iostream>
using namespace std;

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
    root = NULL;
    size = 0;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& other)
{
    root = other.root;
    size = other.size;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete root;
}


template <typename T>
void PriorityQueue<T>::insert(const T& data, int priori)
{
    Node<T>* node = new Node(data, priori);
    if(size==0)
    {
        root = node;
        size++;
    }
    else if(size==1)
    {
        if(root->priori > priori)
        {
            node->next = root;
            root = node;
        }
        else
        {
            root->next = node;
        }
        size++;

    }
    else
    {
        if(root->priori <= priori)
        {
            Node<T>* temp = root;
            while((temp->next !=NULL)&&(temp->next->priori <= priori))
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
        else
        {
            node->next = root;
            root = node;
        }

        size++;
    }

}


template <typename T>
void PriorityQueue<T>::insert(Node<T>* node)
{
    int priori = node->getPriority();

    if(size==0)
    {
        root = node;
        size++;
    }
    else if(size==1)
    {
        if(root->priori > priori)
        {
            node->next = root;
            root = node;
        }
        else
        {
            root->next = node;
        }
        size++;

    }
    else
    {
        if(root->priori <= priori)
        {
            Node<T>* temp = root;
            while((temp->next !=NULL)&&(temp->next->priori <= priori))
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
        else
        {
            node->next = root;
            root = node;
        }

        size++;
    }

}

template <typename T>
Node<T>* PriorityQueue<T>::dequeue()
{
    if(size==0)
        return NULL;
    else if(size==1)
    {
        Node<T>* temp = root;
        root = NULL;
        size--;
        return temp;
    }
    else
    {
        Node<T>* temp = root;
        root = root->next;
        size--;
        return temp;
    }
}

template <typename T>
void PriorityQueue<T>::display()
{
    Node<T>* temp = root;
    if(size==0)
    {
        cout<<"Empty Queue"<<endl;
        return;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
template <class T>
int PriorityQueue<T>::getSize()
{
    return size;
}
template <typename T>
bool PriorityQueue<T>::isEmpty()
{
    if(size==0)
        return true;
    else
        return false;
}


template class PriorityQueue<char>;
template class PriorityQueue<int>;




