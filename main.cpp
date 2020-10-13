#include <iostream>
#include "ArgumentManager.h"
#include "linkedList.h"
#include "Stack.h"
#include <fstream>
using namespace std;
//for removing fix from input file
string trimFix(string str, string subStr){
    size_t pos = str.find(subStr);
    if (pos != string::npos){
        str.erase(pos, subStr.length());
    }
    string ret;
    for(char x : str){
        if(x!=' '){
          ret+=x;
        }
    }
     return ret;
}

string trimCommand(string str, string subStr){
    size_t pos = str.find(subStr);
    if (pos != string::npos){
        str.erase(pos, subStr.length());
    }
    string ret;
    for(char x : str){
        if(x!=' ' && x!='(' && x!=')'){
          ret+=x;
        }
    }
     return ret;
}

int main(int argc, char *argv[]) {
  cout<<"HERE?"<<endl;
 if(argc<2){return -1;}
  ArgumentManager am(argc, argv);

  string inputFileName=am.get("input"),outputFileName=am.get("output"), commandFileName=am.get("command");

  ifstream inputFile, commandFile; ofstream outputFile;
  inputFile.open(inputFileName); 
  commandFile.open(commandFileName); 
  outputFile.open(outputFileName);

  string input; //string for expressions
  linkedList List; Stack stack;
  //get expressions
  cout<<"BEFORE INPUT";
  while(inputFile){
      getline(inputFile, input);
      if(input==""){
        continue;
      }
      size_t found = input.find("prefix");

      if(found!=string::npos){
        input=trimFix(input, "prefix:");
        List.add("prefix",input);
       // cout<<input<<endl;
      }else{
          size_t found=input.find("postfix");
          if(found!=string::npos){
            input=trimFix(input,"postfix:");
            List.add("postfix",input);
            //cout<<input<<endl;
          }
      }

  }

  string command;
  cout<<"BEFORE COMMAND"<<endl;
   while(commandFile){
      getline(commandFile, command);
      if(command==""){continue;}

      else if(command=="printList"){
        cout<<"Print List"<<endl;
        outputFile<<List.print();
      }

      else if(command=="printListBackwards"){
        cout<<"Print List Backwards"<<endl;
        outputFile<<List.reversePrint();
      }

      else if(command=="printReserveSize"){
        cout<<"PRINT RESERVE SIZE"<<endl;
        outputFile<<stack.printSize();
      }

      else if(command=="printReserveTop"){
        cout<<"PRINT RESERVE TOP"<<endl;
        outputFile<<stack.getTop();
        //cout<<stack.getTop();
      }

      else if(command=="flipReserve"){
        cout<<"FLIP RESERVE<"<<endl;
        stack.reverse();
      }

      else if(command=="convertReserve"){
        cout<<"CONVERT RESERVE"<<endl;
        stack.convertReserve();
      }

      else if(command.find("convertList")!=string::npos){
        cout<<"CONVERT LIST"<<endl;
        string condition = trimCommand(command, "convertList");
        List.convert(condition);
    }

      else if(command.find("pushReserve")!=string::npos){
        cout<<"PUSH RESERVE"<<endl;
        string condition = trimCommand(command, "pushReserve");
        
        stack.pushReserve(List, condition);

    }

    else if (command.find("emptyReserve")!=string::npos){
      cout<<"EMPTY RESERVE"<<endl;
      string condition = trimCommand(command, "emptyReserve");
      stack.empty(List, stoi(condition));
    }

    else if (command.find("popReserve")!=string::npos){
      cout<<"POP RESERVE"<<endl;
      string condition = trimCommand(command, "popReserve");
      stack.popReserve(List, stoi(condition));
    }

    else if(command.find("removeList")!=string::npos){
        cout<<"REMOVE LIST"<<endl;
        string condition = trimCommand(command, "removeList");
        List.remove(condition);
    }

  }
  cout<<"AFTER COMMAND"<<endl;

  //}
  
  //Test case 3

 /* cout<<List.print();
  stack.pushReserve(List, "all");
  cout<<List.print();
  stack.empty(List, 999);
  cout<<List.print();

  //Test case 2
  //linkedList List; Stack stack;
  */
  /*cout<<List.print();

  stack.pushReserve(List, "postfix");

  cout<<List.print();
  
  cout<<stack.printSize();
  cout<<stack.getTop();
  stack.convertReserve();
  stack.reverse();
  stack.popReserve(List, 0);
  cout<<List.print();
  
  stack.empty(List, 0);
   cout<<List.print();
   //END TEST CASE 2


  //List.remove("postfix");
  //List.remove("prefix");
  
  //Test case 1*/

  /*cout<<List.print();

  cout<<List.reversePrint();
  List.convert("postfix");
  cout<<List.print();
  List.convert("prefix");
  cout<<List.print();
  List.convert("all");
  cout<<List.print();
  List.convert("0");
  cout<<List.print();*/

  //end test case 1
  
  /*stack.add("postfix","AB+CD-*");
  cout<<stack.getTop();
  stack.top.head->convertFix();
  cout<<stack.getTop();
  cout<<stack.printSize();*/

  //linkedList list;
  //Stack stack;

  /*stack.add("postfix", "5");
  stack.add("prefix", "4");
  stack.add("prefix","3");
  stack.add("postfix","2");
  stack.add("postfix","1");

  cout<<stack.print();
  stack.reverse();
  cout<<stack.print();
  cout<<stack.size;*/

 /* list.add("postfix", "AB+CD-");
  list.add("prefix", "+*ABC");
  list.add("prefix", "+A*B/C-EF");
  list.add("postfix", "AB-C-D/");
  cout<<list.print();
  list.insertBeg("prefix", "TEST");
  cout<<list.print();
  list.insertBeg("postfix", "TEST1");
  cout<<list.print();
  
  //Node* trav= list.head;

  /*list.remove("prefix");
  //list.remove("postfix");
  cout<<list.print();
  stack.pushReserve(list, "postfix");
  list.add("postfix", "DARKNESS");
  list.convert("all");
  list.remove("postfix");
  cout<<list.print();
  stack.convertReserve();
  cout<<stack.printSize();
  stack.reverse();
  stack.popReserve(list, 0);
  cout<<stack.getTop();
  cout<<stack.printSize();
  //cout<<"LIST SIZE:"<<list.size;
  stack.empty(list,0);
  
  cout<<list.print();
 //list.add("prefix", "D+A+B");
  
  //list.remove("all");
  //cout<<list.print();
  //cout<<"LIST SIZE:"<<list.size<<endl;
  
  //cout<<stack.top->fix<<stack.top->equation;
  //cout<<stack.top->bottom->equation;
  //cout<<stack.print();
  //cout<<stack.printSize();
  //cout<<stack.getTop();
/*
 // stack.add("prefix","0");
  cout<<stack.getTop();
  cout<<stack.print();
  //stack.popReserve(list, 0);

  cout<<stack.getTop();
 
  cout<<"LIST SIZE:"<<list.size<<endl;
  cout<<"STACK SIZE:"<<stack.size<<endl;

  stack.pushReserve(list, "3");
  cout<<stack.print();
  cout<<list.print();
  cout<<stack.getTop();
  cout<<list.reversePrint();
  cout<<list.size;
  list.remove("1");
  cout<<list.print();

  list.convert("3");
  cout<<list.print();
  //cout<<list.head->fix;
  stack.convertReserve();
  cout<<stack.getTop();*/

}
// ./main "input=input31.txt; output=output31.txt; command=command31.txt"
//./main "input=input32.txt; output=output32.txt; command=command32.txt"
//./main "input=input33.txt; output=output33.txt; command=command33.txt"
// ./main "input=input34.txt; output=output34.txt; command=command34.txt"
// ./main "input=input35.txt; output=output35.txt; command=command35.txt"
// ./main "input=input36.txt; output=output36.txt; command=command36.txt"
// ./main "input=input37.txt; output=output37.txt; command=command37.txt"
// ./main "input=input38.txt; output=output38.txt; command=command38.txt"
// ./main "input=input39.txt; output=output39.txt; command=command39.txt"