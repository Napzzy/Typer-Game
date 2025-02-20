#include "grid.h"

template <typename T>
Grid<T>::Grid() : _grid_nodes(nullptr)
{
    _head = nullptr;
    _RandomWords = RandomWords();
}

template <typename T>
void Grid<T>::GridCreation(int Horizontal_X, int Vertical_Y)
{
    node<T> * prev_node; 
    node<T> * above; 
    
    for (int y = 0; y < Vertical_Y ; y++)
    {
        for (int x = 0; x < Horizontal_X; x++)
        {
            Node<T> *Item = new node<T>(_RandomWord[RandomNumber(_RandomWords.size())]);
           
        }
    }
    
}

template <typename T> 
int Grid<T>::RandomNumber(int Size)
{
    srand(time(0));
    int random_number = rand() % size;
    return random_number; 
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