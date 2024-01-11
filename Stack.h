#pragma once

struct Node
{
    int val;
    Node* next;
};

class Stack
{
public:
    ~Stack();

    int Size(){return size;}
    int Get(int index);
    void Set(int value, int index);
    void Emplace(int value);
    void Insert(int value);
    void InsertAt(int value, int index);
    void Pop();
    void Pull();
    void Remove(int index);

private:
    Node* At(int index);

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};