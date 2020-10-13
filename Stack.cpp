#include "Stack.h"
#include "linkedList.h"
#include <iostream>
#include <string>
using namespace std;

string Stack::print(){
    string str;
      str+="STACK:\n";
      if(this->top.head==nullptr){
        str+="EMPTY\n";
        return str;
      }else{
        Node* trav = this->top.head;
        
        while(trav){
          str+=trav->fix+":"+trav->equation+"\n";
          trav=trav->next;
        }
      }
      return(str+"\n");

    }

void Stack::add(string fix, string equation){
      Node* temp = new Node(fix, equation);
  
      if(this->top.head==nullptr){
        this->top.head=temp;
        size++;
      }else{
        temp->next=top.head;

        size++;
        this->top.head=temp;
      }
    }
string Stack::printSize(){
  return("Reserve Size: "+to_string(this->size)+"\n"+"\n");
}

string Stack::getTop(){
  if(this->top.head==nullptr){
    return("Top of Reserve: EMPTY\n\n");
  }
  return("Top of Reserve: "+(this->top.head->fix)+(':')+(this->top.head->equation)+"\n"+"\n");
}

void Stack::popReserve(linkedList& list, int pos){
  if(top.head==nullptr){
    return;
  }
    if(pos>list.size){
      list.add(top.head->fix, top.head->equation);
      top.head=top.head->next;
      this->size--;
      return;
    }else if(pos<=0){
      list.insertBeg(top.head->fix, top.head->equation);

      top.head=top.head->next;
      this->size--;
      return;
    }

    Node* temp = new Node(top.head->fix, top.head->equation);
    Node* trav = list.head;
    for(int i=0; i<pos-1; i++){
        trav=trav->next;
    }
    Node* Next = trav->next;
    temp->prev=trav;
    temp->next=Next;
    //delete trav->next;
    trav->next=temp;
    list.size++;

    Node* newHead = top.head->next;
   // delete top.head;
    top.head=newHead;
    this->size--;

}

void Stack::convertReserve(){
  if(top.head==nullptr){
    return;
  }
  top.head->convertFix();
}

void Stack::pushReserve(linkedList& list, string condition){
  if(list.head==nullptr){
    cout<<"NULL HEAD"<<endl;
    return;
  }
  if(isdigit(condition[0])){
    cout<<"DIGIT CONDITION"<<endl;
    int pos=stoi(condition);
    if(pos>list.size){
      return;
    }else if(pos<=0){
      add(list.head->fix, list.head->equation);
      list.head=list.head->next;
      list.size--;
      return;
    }else{
      Node* trav=list.head;
      for(int i=0; i<pos-1;i++){
      trav=trav->next;
      //cout<<"TRAV PREV:"<<trav->prev->fix;
    }
    Node* Next = trav->next->next;
    add(trav->next->fix, trav->next->equation);
   //delete trav->next; 
    trav->next=Next;
    list.size--;
    return;
  }
}else if(condition=="all"){
    Node* trav = list.head;
    while(trav!=nullptr){
      add(trav->fix, trav->equation);
      trav=trav->next;
    }
    //delete list.head; 
    list.head=nullptr;
    list.size=0;
  }else{
    cout<<"CONDITION: "<<condition<<endl;
  Node* trav = list.head;
  while(trav!=nullptr){
    cout<<"RUNNING CONDITION"<<endl;
    if(trav->fix==condition){
      list.size--;
      if(trav==list.head){
        cout<<"HEAD IS TRAV"<<endl;
        //list.size--;
        add(list.head->fix, list.head->equation);
      
        list.head=list.head->next;
        //trav=list.head;
    
      }else if(trav==list.tail){
        cout<<"HEAD IS TAIL"<<endl;
        Node* Prev = list.tail->prev;
        Prev->next=nullptr;

        Prev->prev=list.tail->prev->prev;

        add(list.tail->fix, list.tail->equation);

        //delete list.tail;
  
        list.tail=Prev;
        
      }else{
        cout<<"HEAD IS NEITHER HEAD NOR TAIL"<<endl;
        add(trav->fix, trav->equation);

        trav->prev->next=trav->next;
        Node* Prev = trav->prev;
        Node* Next = trav->next;
        
        Prev->next=Next;
        Next->prev=Prev;
        //delete trav;
  
      }
    }
    trav=trav->next;
  }

}
}
void Stack::reverse(){
  if(top.head==nullptr){
    return;
  }
  Node* trav = top.head;
  int trueSize=this->size;
  while(trav!=nullptr){
    add(trav->fix, trav->equation);
    trav=trav->next;
  }

  Node* check = top.head;
  for(int i=0; i<trueSize-1;i++){
      check=check->next;
  }
 // delete check->next;
  check->next=nullptr;
  this->size=trueSize;
}

void Stack::empty(linkedList& list, int pos){
  if(top.head==nullptr){
    return;
  }
  if(pos>list.size){
    while(top.head){
      list.add(top.head->fix, top.head->equation);
      top.head=top.head->next;
    }
   // delete top.head;
   top.head=nullptr;
    size=0;
  }else if(pos<=0){
    while(top.head){
     list.insertBeg(top.head->fix, top.head->equation);
      top.head=top.head->next;
      size--;
    }
   // return;
  }else{
    while(top.head!=nullptr){
      Node* temp = new Node(top.head->fix, top.head->equation);
      Node* trav=list.head;
      for(int i=0; i<pos-1; i++){
        trav=trav->next;
      }
      temp->prev=trav;
      temp->next = trav->next;
      //delete trav->next;
      trav->next = temp;

      top.head=top.head->next;

    }
  }
}