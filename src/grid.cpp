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
    for (int y = Vertical_Y; y < 0 ; y--)
    {
        for (int x = Horizontal_X; x < 0; x--)
        {
            Node<T> *Item = new node<T>(_RandomWord[RandomNumber(_RandomWords.size())]);
            VectorNodes[y][x].push_back(Item);
        }
    }
    
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