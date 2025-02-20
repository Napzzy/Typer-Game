#include "grid.h"

template <typename T>
Grid<T>::Grid() 
{
    _Head = nullptr;
    _Tail = nullptr;
    Center = nullptr;
    _RandomWords = RandomWords();
    GridCreation(); 
}

template <typename T>
Grid<T>::Grid(int X, int Y) 
{
    _Head = nullptr;
    _Tail = nullptr;
    Center = nullptr;
    _RandomWords = RandomWords();
    GridCreation(X, Y);
}

/*
===========
BIG THREE
===========
*/

template <typename T>
Grid<T>::~Grid()
{

}


template <typename T>
Grid<T>::Grid(const Grid &copyThis)
{

}

template <typename T>
Grid<T> &Grid<T>::operator=(const Grid &RHS)
{


}

template <typename T>
void Grid<T>::GridCreation(int Horizontal_X = 3, int Vertical_Y = 3)
{
    node<T> * PrevRowHead= nullptr;
    
    for (int y = 0; y < Vertical_Y; y++)
    {
        node<T> *prev_node = nullptr;
        node<T> *RowHead = nullptr; 
        for (int x = 0; x < Horizontal_X; x++)
        {
            node<T> *Item = new node<T>(RandomNumber(_RandomWords.size()));

            if (x == 0 && y == 0)
            {
                _Head = Item;
            }

            if(x == Horizontal_X -1 && y == Vertical_Y - 1)
            {
                _Tail = Item; 
            }

            if(x == Horizontal_X / 2 && y == Vertical_Y / 2)
            {
                Item->_item = "___"; 
                Center = Item; 
            }
            
            if(prev_node)
            {
                prev_node->_right = Item;
                Item->_left = prev_node; 
            }
            else
                RowHead = Item; 
            
            prev_node = Item;
            
            if(PrevRowHead)
            {
                node<T> *AboveWalker = PrevRowHead;
                for (int j = 0; j < x; j++){
                    AboveWalker = AboveWalker->_right;
                }

                Item->_up = AboveWalker;
                AboveWalker->_down = Item; 
            }
        }
        PrevRowHead = RowHead; 
    }
}

template <typename T>
string Grid<T>::RandomNumber(int Size)
{
    srand(time(0));
    int random_number = rand() % size;

    int random_20 = rand() % 100; 

    if(random_20 < 20)
    {
        return "XXX";
    }
    return _RandomWords[random_number];
}

template <typename T>
vector<string> Grid<T>::RandomWords()
{
    vector<string> Words;
    string Text;

    ifstream inputFile("WordData.txt");

    if (!inputFile.is_open())
    {
        cout << "Error, opening file!!" << endl;
        exit(0);
    }

    while (getline(inputFile, Text))
    {
        Words.push_back(Text);
    }
    return Words;
}

template <typename T>
void Grid<T>::PrintGrid(node<T> *&Head)
{
    node<T> *Walker = Head;

    while(Walker->_down != nullptr) 
    {
        node<T> *StartPos = Walker; 
        while(StartPos->_right) 
        {
            cout << StartPos->_item;
            StartPos = StartPos->_right; 
        }

        Walker = Walker->_down; 
    }
}

