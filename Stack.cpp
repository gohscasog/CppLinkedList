#include "Stack.h"

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

Node* Stack::At(int index)
{
    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Error: index out of range");
    }

    if(size == 0)
    {
        throw std::exception("Error: empty container");
    }

    auto ptr = head;
    for(int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

int Stack::Get(int index)
{
    return Stack::At(index)->val;
}

void Stack::Set(int value, int index)
{
    Stack::At(index)->val = value;
}

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
    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Error: index out of range");
    }

    if(index == 0 || size == 0)
    {
        Stack::Emplace(value);
        return;
    }

    if(index == size - 1)
    {
        Stack::Insert(value);
        return;
    }

    Node* node = new Node{value, nullptr};
    Node* prev = Stack::At(index - 1);
    Node* curr = prev->next;
    prev->next = node;
    node->next = curr;
    size++;
}

void Stack::Pop()
{
    Node* post = head->next;
    delete head;
    head = post;
    size--; 
}

void Stack::Pull()
{
    if(size == 0)
    {
        throw std::exception("Error: empty container");
    }

    if(size > 1)
    {
        Node* node = Stack::At(size - 2);
        node->next = nullptr;

        delete tail;
        tail = nullptr;
    } 
    else
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    size--;
}

void Stack::Remove(int index)
{
    if(index < 0 || index >= size)
    {
        throw std::out_of_range("Error: index out of range");
    }

    if(size == 0)
    {
        throw std::exception("Error: empty container");
    }

    if(index == 0)
    {
        Stack::Pop();
    }
    else if(size == 1 || index == size - 1)
    {
        Stack::Pull();
    }
    else
    {
        Node* prev = Stack::At(index - 1);
        Node* curr = prev->next;
        prev->next = curr->next;
        delete curr;
        size--;
    }
}