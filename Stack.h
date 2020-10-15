#ifndef STACK_H
#define STACK_H
#include <vector>
#include <string>
#include "linkedList.h"
using namespace std;

class Stack{
  public:
    int size=0;
    
    linkedList top;
  
    void add(string fix, string equation);
     
    string print();
      
    string printSize();

    void empty(linkedList& list, int pos); 

    string getTop();

    void popReserve(linkedList& list, int pos);

    void convertReserve();

    void pushReserve(linkedList& list, string condition);

    void reverse();
};

#endif
