#ifndef GRID_H
#define GRID_H

#include "../node/node.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>

class Grid
{
public:
    Grid();
    Grid(int X, int Y);

    // Big three
    ~Grid();
    // Grid(const Grid &copyThis);
    // Grid &operator=(const Grid &RHS);

    node<string>* GridCreation(int Horizontal_X, int Vertical_Y);

    void Play();

    void PrintGrid(node<string> *&Head);

    vector<string> VectorOfWords();

    string RandomWord(int Size);

    node<string>* ShiftLeft(node<string>* &Heads);
    node<string>* ShiftRight(node<string>* &Heads);
    node<string> *ShiftUp(node<string> *&Heads);
    node<string> *ShiftDown(node<string> *&Heads);

    node<string>* SearchArea(node<string>* CenterPtr, string ITEM_TO_FIND, node<string> *&Head);

private:
    node<string> *Center;
    node<string> *_Head;
    vector<string> _RandomWords;
    int GridSize_X;
    int GridSize_Y;
    string InPutWord;
    int Score; 
};

#endif