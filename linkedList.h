#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
  Node* prev=nullptr; Node* next=nullptr;
  string fix, equation;
  Node(){};

  void convertFix();

  Node(string fix, string val){
    this->fix=fix;
    this->equation=val;
  }
};

class linkedList{
  public:
    Node* head=nullptr; Node* tail=nullptr;
    int size = 0;

    void add(string fix, string equation){
      if(this->head==nullptr){
        this->head=new Node(fix, equation);
        tail=head;
        size++;
      }else{
        Node* temp = new Node(fix, equation);temp->prev=tail; 
        tail->next=temp;
        
        //delete tail;
        this->tail=temp;
        size++;
      }
    }

    void remove(string condition);

    void addPos(int val);

    void convertPos(int val);

    void convert(string condition);
  
    string print();

    string reversePrint();

    void insertBeg(string fix, string equation){
      Node* temp = new Node(fix, equation);
      temp->prev=nullptr;
      temp->next=head;
      head->prev=temp;
      //delete head;
      head=temp;
      size++;
    }
};

#endif
