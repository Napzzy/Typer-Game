
#include "grid.h"

Grid::Grid()
{
    _Head = nullptr;
    Center = nullptr;
    _RandomWords = VectorOfWords();

    GridSize_X = 5;
    GridSize_Y = 5;
    GridCreation(5, 5);
}

Grid::Grid(int X, int Y)
{
    _Head = nullptr;
    Center = nullptr;
    _RandomWords = VectorOfWords();

    GridSize_X = X;
    GridSize_Y = Y;
    GridCreation(X, Y);
}

Grid::~Grid()
{
    // node<string> *Walker = _Head;

    // while (Walker != nullptr)
    // {
    //     node<string> *nextRow = Walker->_down;
    //     node<string> *StartPos = Walker;
    //     while (StartPos->_right)
    //     {
    //         node<string> *TempNode = StartPos->_right;
    //         delete StartPos;
    //         StartPos = TempNode;
    //     }

    //     Walker = nextRow;
    // }
}

node<string> *Grid::GridCreation(int Horizontal_X, int Vertical_Y)
{
    node<string> *PrevRowHead = nullptr;

    for (int y = 0; y < Vertical_Y; y++)
    {
        node<string> *prev_node = nullptr;
        node<string> *RowHead = nullptr;
        for (int x = 0; x < Horizontal_X; x++)
        {
            node<string> *Item = new node<string>(RandomWord(_RandomWords.size()));

            if (x == 0 && y == 0)
            {
                _Head = Item;
            }
            if (x == Horizontal_X / 2 && y == Vertical_Y / 2)
            {
                Item->_item = "___";
                Center = Item;
            }

            if (prev_node)
            {
                prev_node->_right = Item;
                Item->_left = prev_node;
            }
            else
                RowHead = Item;

            prev_node = Item;

            if (PrevRowHead)
            {
                node<string> *AboveWalker = PrevRowHead;
                for (int j = 0; j < x; j++)
                {
                    AboveWalker = AboveWalker->_right;
                }

                Item->_up = AboveWalker;
                AboveWalker->_down = Item;
            }
        }
        PrevRowHead = RowHead;
    }

    return _Head;
}

string Grid::RandomWord(int Size)
{
    int random_number = rand() % Size;
    int random_20 = rand() % 100;
    if (random_20 < 20)
    {
        return "XXX";
    }
    return _RandomWords[random_number];
}

vector<string> Grid::VectorOfWords()
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

void Grid::PrintGrid(node<string> *&Head)
{
    node<string> *Walker = Head;

    while (Walker != nullptr)
    {
        node<string> *StartPos = Walker;
        while (StartPos)
        {
            cout << *StartPos;
            StartPos = StartPos->_right;
        }
        cout << endl;
        Walker = Walker->_down;
    }
}

node<string> *Grid::SearchArea(node<string> *CenterPtr, string ITEM_TO_FIND, node<string> *&Head)
{
    if (CenterPtr->_up && CenterPtr->_up->_item == ITEM_TO_FIND)
        return ShiftDown(Head);
    else if (CenterPtr->_down && CenterPtr->_down->_item == ITEM_TO_FIND)
        return ShiftUp(Head);
    else if (CenterPtr->_left && CenterPtr->_left->_item == ITEM_TO_FIND)
        return ShiftRight(Head);
    else if (CenterPtr->_right && CenterPtr->_right->_item == ITEM_TO_FIND)
        return ShiftLeft(Head);
    else if ((CenterPtr->_left && CenterPtr->_left->_item == "XXX") && (CenterPtr->_down && CenterPtr->_down->_item == "XXX") &&
             (CenterPtr->_right && CenterPtr->_right->_item == "XXX") && (CenterPtr->_up && CenterPtr->_up->_item == "XXX"))
        return CenterPtr;
    else
        return nullptr;
}

node<string> *Grid::ShiftLeft(node<string> *&Heads)
{
    node<string> *WalkerRow = Heads;

    for (int y = 0; y < GridSize_Y; y++)
    {
        node<string> *WalkerX = WalkerRow;
        for (int x = 0; x < GridSize_X - 1; x++)
        {
            if (WalkerX != Center && WalkerX->_right != Center)
            {
                WalkerX->_item = WalkerX->_right->_item;
            }
            else if (WalkerX->_left == Center)
            {
                WalkerX->_item = RandomWord(_RandomWords.size());
            }
            WalkerX = WalkerX->_right;
        }

        WalkerX->_item = RandomWord(_RandomWords.size());
        WalkerRow = WalkerRow->_down;
    }

    return Heads;
}

node<string> *Grid::ShiftRight(node<string> *&Heads)
{
    node<string> *WalkerRow = Heads;

    for (int y = 0; y < GridSize_Y; y++)
    {
        node<string> *WalkerX = WalkerRow;
        while (WalkerX->_right != nullptr) // Start from the far right
        {
            WalkerX = WalkerX->_right;
        }

        while (WalkerX->_left != nullptr) // Shift everything
        {
            if (WalkerX != Center && WalkerX->_left != Center)
            {
                WalkerX->_item = WalkerX->_left->_item;
            }
            if (WalkerX->_left == Center)
                WalkerX->_item = RandomWord(_RandomWords.size());
            WalkerX = WalkerX->_left;
        }
        if (WalkerX != Center)
            WalkerX->_item = RandomWord(_RandomWords.size());
        WalkerRow = WalkerRow->_down;
    }

    return Heads;
}

node<string> *Grid::ShiftUp(node<string> *&Heads)
{
    node<string> *WalkerRow = Heads;

    while (WalkerRow->_down)
    {
        node<string> *WalkerX = WalkerRow;
        while (WalkerX)
        {
            if (WalkerX->_down != nullptr && WalkerX->_down != Center && WalkerX != Center)
            {
                WalkerX->_item = WalkerX->_down->_item;
            }
            else if (WalkerX->_down == Center)
            {
                WalkerX->_item = RandomWord(_RandomWords.size());
            }
            WalkerX = WalkerX->_right;
        }
        WalkerRow = WalkerRow->_down;
    }

    WalkerRow = WalkerRow;
    while (WalkerRow)
    {
        WalkerRow->_item = RandomWord(_RandomWords.size());
        WalkerRow = WalkerRow->_right;
    }
    return Heads;
}

node<string> *Grid::ShiftDown(node<string> *&Heads)
{
    node<string> *LastRow = Heads;

    while (LastRow->_down != nullptr)
    {
        LastRow = LastRow->_down;
    }

    while (LastRow->_up)
    {
        node<string> *WalkerX = LastRow;
        while (WalkerX)
        {
            if (WalkerX != Center && (WalkerX->_up != Center))
            {
                WalkerX->_item = WalkerX->_up->_item;
            }
            else if (WalkerX->_up == Center)
            {
                WalkerX->_item = RandomWord(_RandomWords.size());
            }
            WalkerX = WalkerX->_right;
        }
        LastRow = LastRow->_up;
    }

    while (LastRow)
    {
        LastRow->_item = RandomWord(_RandomWords.size());
        LastRow = LastRow->_right;
    }
    return Heads;
}

void Grid::Play()
{

    while (true)
    {
        PrintGrid(_Head);
        cout << "Please input word (Press E to exit) : ";
        getline(cin, InPutWord);
        if (InPutWord == "e" || InPutWord == "E")
            break;

        node<string> *Shift = SearchArea(Center, InPutWord, _Head);
        if (Shift == nullptr)
        {
            cout << "No word wrong!!\n";
        }
        else if (Shift == Center)
        {
            cout << "You lost the time!";
            break;
        }
    }
}