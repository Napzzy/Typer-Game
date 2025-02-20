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
    
    void GridCreation(int Horizontal_X, int Vertical_Y);
    
    vector<string> RandomWords();

    int RandomNumber(int Size); 

    friend ostream &operator<<(ostream &outs, const node<T> &PrintThis)
    {
        outs << "[ " << PrintThis._item << "] ->";
        return outs;
    }
    
private:
    node<T> * Center; 
    node<T> * List; 
    vector<string> _RandomWords;
};

#endif

