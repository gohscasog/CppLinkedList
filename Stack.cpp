#include "Stack.h"

void Stack::Emplace(int val)
{
    Node* node = new Node{val, nullptr};

    if(head)
    {
        node->next = head;
        head = node;
    }
    else
    {
        head = node;
        tail = head;
    }

    size++;
}

void Stack::Insert(int val)
{
    if(head)
    {
        Node* node = new Node{val, nullptr};
        tail->next = node;
        tail = node;
        size++;
    }
    else
    {
        this->Emplace(val);
    }
}

void Stack::Pop()
{
    if(tail)
    {
        delete tail;
        tail = nullptr;
    } 
}