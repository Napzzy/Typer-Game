#ifndef GRID_H
#define GRID_

#include "../node/node.h"
#include "WordGame.cpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

template <typename T>
class Grid
{
public:
    Grid();
    Grid(int X, int Y);

    // Big three
    ~Grid();
    Grid(const Grid &copyThis);
    Grid &operator=(const Grid &RHS); 

    void GridCreation(int Horizontal_X, int Vertical_Y);

    void Play();

    void PrintGrid(node<T> *&Head);

    vector<string> RandomWords();

    string RandomNumber(int Size);

    friend ostream &operator<<(ostream &outs, const node<T> &PrintThis)
    {
        outs << "[ " << PrintThis._item << "] ";
        return outs;
    }

private:
    node<T> *Center;
    node<T> *_Head;
    node<T> *_Tail;
    vector<string> _RandomWords;
};

#endif
