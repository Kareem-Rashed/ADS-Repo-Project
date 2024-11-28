//
// Created by Kareem Rashed on 10/11/2024.
//

#include "Node.h"
#include <iostream>
using namespace std;


template <typename T>
T Node<T>::getData() const
{
    return data;
}


template <typename T>
int Node<T>::getPriority() const
{
    return priori;
}
template class Node<char>;
template class Node<int>;