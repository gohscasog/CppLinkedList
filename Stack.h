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

    Node* At(int index);
    int Size(){return size;}
    void Emplace(int value);
    void Insert(int value);
    void InsertAt(int value, int index);
    void Remove(int index);
    void Pop();

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};