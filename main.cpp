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

  ifstream inputFile(inputFileName), commandFile(commandFileName); ofstream outputFile(outputFileName);

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
}
//Command-line test cases
// ./main "input=input31.txt; output=output31.txt; command=command31.txt"
//./main "input=input32.txt; output=output32.txt; command=command32.txt"
//./main "input=input33.txt; output=output33.txt; command=command33.txt"
// ./main "input=input34.txt; output=output34.txt; command=command34.txt"
// ./main "input=input35.txt; output=output35.txt; command=command35.txt"
// ./main "input=input36.txt; output=output36.txt; command=command36.txt"
// ./main "input=input37.txt; output=output37.txt; command=command37.txt"
// ./main "input=input38.txt; output=output38.txt; command=command38.txt"
// ./main "input=input39.txt; output=output39.txt; command=command39.txt"
