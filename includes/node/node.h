

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct node
{
    node(const T &item = T(), node *right = nullptr, node *down = nullptr, node * left = nullptr, node* up = nullptr) 
    : _item(item), _right(right), _down(down), _left(left), _up(up)
    {
    }

    friend ostream &operator<<(ostream &outs, const node<string> &PrintThis)
    {
        outs << "[ " << setw(5) << right << PrintThis._item << " ] ";
        return outs;
    }

    T _item;
    node<T> *_right;
    node<T> * _up;
    node<T> * _left; 
    node<T> *_down; 
};

#endif