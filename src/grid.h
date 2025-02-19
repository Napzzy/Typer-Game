#ifndef GRID_H
#define GRID_

#include "../node/node.h"
#include "WordGame.cpp"

#include <vector>
#include <iostream>
#include <fstream>

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
    vector<vector<node>> VectorNodes; 
    vector<string> _RandomWords;
};

#endif

