#pragma once

struct Node
{
    int val;
    Node* next;
};

class Stack
{
public:
    Node* Top(){return head;}
    int Size(){return size;}
    void Emplace(int val);
    void Insert(int val);
    void Pop();

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* prev = nullptr;
    int size = 0;
};