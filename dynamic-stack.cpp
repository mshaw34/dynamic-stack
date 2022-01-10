#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    size_=0;
    capacity_ = 16;
    init_capacity_ = capacity_;
    items_ = new StackItem[capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
    size_=0;
    capacity_ = capacity;
    init_capacity_ = capacity;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack()
{
    delete items_;
}

bool DynamicStack::empty() const
{
    if (size_==0)
        return true;
    return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
    if (size_>=capacity_){ // full
        capacity_ *= 2;
        StackItem* Temp = new StackItem [capacity_];
        for (int i = 0; i < size_; i++){
            Temp[i] = items_[i];
        }
        delete [] items_;
        items_ = Temp;
    }
    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop()
{
    if (empty()){
        return EMPTY_STACK;
    }
    StackItem top = items_[size_-1];
    size_--;
    if ((size() <= (capacity_ / 4) && ((capacity_ / 2) >= init_capacity_))){
        capacity_ /= 2;
        StackItem* Temp = new StackItem [capacity_];
        for (int i = 0; i < size_; i++){
            Temp[i] = items_[i];
        }
        delete [] items_;
        items_ = Temp;
    }
    return top;
}

DynamicStack::StackItem DynamicStack::peek() const
{
    if (empty())
        return EMPTY_STACK;
    return items_[size_-1];
}

void DynamicStack::print() const
{
    for (int i = 0; i < capacity_; i++){
        std::cout <<i << " : "<< items_[i]<<"\n";
    }
}
