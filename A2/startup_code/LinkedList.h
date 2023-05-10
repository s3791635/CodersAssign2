#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

#include <string>
#include <string.h>

#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>
#include <random>

using std::string;
using std::vector;


class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    bool Insert(Stock * data);
    Node* Peek();
    void DisplayItems();

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H

