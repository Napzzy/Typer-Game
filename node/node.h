

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct node
{
    node(const T &item = T(), node *right = nullptr, node *down = nullptr) : _item(item), _next(right), _down(down)
    {
    }
    T _item;
    node<T> *_next;
    node<T> *_down; 
};

#endif