#include "linkedList.h"
#include "Stack.h"
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='$'){
	  return true;
  }
	return false;
}

//this function was sourced from https://www.geeksforgeeks.org/postfix-prefix-conversion/
string postToPre(string equation){
    stack<string> s;
    int length = equation.size();
    for (int i = 0; i < length; i++){
        if (isOperator(equation[i])){
          string op1 = s.top();
          s.pop();
          string op2 = s.top();
          s.pop();
 
          string temp = equation[i] + op2 + op1;
          s.push(temp);
        }else{
          s.push(string(1, equation[i]));
        }
    }
 
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}

//this function was sourced from https://www.geeksforgeeks.org/prefix-postfix-conversion/
string preToPost(string equation) { 
  stack<string> s; 
  int length = equation.size(); 
  for (int i = length - 1; i >= 0; i--){ 
    if (isOperator(equation[i])){ 
      string op1 = s.top(); s.pop(); 
      string op2 = s.top(); s.pop(); 
      string temp = op1 + op2 + equation[i]; 
      s.push(temp); 
    }else{ 
      s.push(string(1, equation[i])); 
    } 
  } 
  return s.top(); 
}
void Node::convertFix(){
  if(this->fix=="postfix"){
    this->fix="prefix";
    this->equation=postToPre(this->equation);
    return;
  }
    this->fix="postfix";
    this->equation=preToPost(this->equation);
  }

void linkedList::remove(string condition){
  if(head==nullptr){
    return;
  }
  if(condition=="all"){
    //delete head; 
    head=nullptr;
    this->size=0;
    return;
  }

  if(isdigit(condition[0])){
    int pos=stoi(condition);
    if(pos>this->size){
      return;
    }
    if(pos<=0){
      this->head=this->head->next;
      size--;
      return;
    }

    Node* trav=head;
    for(int i=0; i<pos-1;i++){
      trav=trav->next;
    }
    Node* Next = trav->next->next;
    //delete trav->next;
    trav->next=Next;
    Next->prev=trav;
    size--;
    return;
  }
    Node* trav=head;
    while(trav!=nullptr){
      if(trav->fix==condition){
          this->size--;
          if(trav==head){
            head=head->next;
            
          }else if(trav==tail){
            Node* Prev = tail->prev;
            Prev->next=nullptr;
            //delete trav;
            tail=Prev;
            if(tail==head){
              cout<<"HEADBUTT"<<endl;
              head=tail;
            }

          }else{
            Node* Next = trav->next;
            Node* Prev= trav->prev;
            Prev->next=Next;
            Next->prev=Prev;
            //delete trav;
            trav=Prev;
          }
      } trav=trav->next;
      }
  }
string linkedList::print(){
 
  string str;
  str+="List:\n";
      if(head==nullptr){
          str+="EMPTY\n";
          return (str+"\n");
      }else{ 
        
        Node* trav=head;
        while(trav!=nullptr){
          str+=trav->fix+":"+trav->equation+"\n";
          trav=trav->next;
        }
      }
      return(str+"\n");
}

string linkedList::reversePrint(){
  string ret="Reversed List:\n";
  vector<string> reverse;
  Node* trav=head;
  if(head==nullptr){
    ret+="EMPTY\n";
    return (ret+'\n');
  }
  while(trav!=nullptr){
    reverse.push_back(trav->fix+':'+trav->equation+'\n');
    trav=trav->next;
  }
  for(int i=reverse.size()-1; i>=0; i--){
    ret+=reverse.at(i);
  }
  return(ret+'\n');
}

void linkedList::convert(string condition){
  if(this->head==nullptr){
    return;
  }

  if(isdigit(condition[0])){
    int pos=stoi(condition);
    if(pos<=0){
      //cout<<"EUREKA!";
      this->head->convertFix();
    }else if(pos>size){
      return;
    }else{
 
    Node* trav = head;
    for(int i=0; i<pos; i++){
        trav=trav->next;
    }
    trav->convertFix();
  }
}

  if(condition=="all"){
    Node* trav=head;
    while(trav!=nullptr){
      trav->convertFix();
      trav=trav->next;
    }
    return;
  }
  Node* trav = head;
  while(trav!=nullptr){
    if(trav->fix==condition){
      trav->convertFix();
    }
    trav=trav->next;
  }
}
