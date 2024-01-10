#include "Stack.h"

void Stack::Emplace(int value)
{
    Node* node = new Node{value, nullptr};

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

void Stack::Insert(int value)
{
    if(head)
    {
        Node* node = new Node{value, nullptr};
        tail->next = node;
        tail = node;
        size++;
    }
    else
    {
        Stack::Emplace(value);
    }
}

void Stack::InsertAt(int value, int index)
{
    // TODO:
}

void Stack::Pop()
{
    if(!size)
    {
        throw std::exception("Error: empty container");
    }

    if(size == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    if(tail)
    {
        // TODO:
        // delete tail;
        // tail = nullptr; //change to tail = prev;
        // size--;

        // auto prev = Stack::At(size - 1);
        // tail = prev;
    } 
}

Node* Stack::At(int index)
{
    if(!size)
    {
        throw std::exception("Error: empty container");
    }

    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Error: index out of range");
    }

    auto ptr = head;
    for(int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

void Stack::Remove(int index)
{
    if(!size)
    {
        throw std::exception("Error: empty container");
    }

    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Error: index out of range");
    }

    if(index == size - 1)
    {
        Stack::Pop();
    }

    auto ptr = Stack::At(index);
    delete ptr;
    ptr = nullptr;
    size--;
}

Stack::~Stack()
{
    for(int i = 0; i < size; i++)
    {
        delete Stack::At(i);
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}