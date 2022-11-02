//
//  main.cpp
//  linkedLIst1
//
//  Created by Habeeb Awolumate on 4/13/22.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                            ECC CIS-223 Fall 2020                                                    //
//                                                                                                    //
//    Type of Assignment:        Lab                                                                         //
//    Section Number            223-100                                                                    //
//    Author:             Habeeb Awolumate                                                                                //
//    File Name:                friend.cpp                                            //
//                                                                                                    //
//    Purpose of Program:                                                                                //
//        THe purpose of this code is to practice the use of friend functions              //
//                                                  //
//                                                                                                    //
//  Algorithm:                                                                                        //
//    1. create a struct called Node that has two member variables                                 //
//    2. create a type def pointer definer that can be used to creat dynamic object of type Node                                                      //
//    3. Create a function that can be use to inser a Node to a list                                       //
//    4. Create a fucntion that can be used to seach a Node                            //
//    5.  Create a function that can be used to print out all the Nopdes in the List.

#include <iostream>
#include <cstddef>
#include <string>
using namespace std;


struct Node
{
    string item;
    int num;
    Node* Next;
};

typedef Node* NodePtr;
NodePtr search(NodePtr head, string an_item);  //to search for a node in a linked list

void head_insert(NodePtr& head, string an_item, int a_number); //to create a new node and add it tp the list
void show_list(NodePtr head); //to print out the list of Nodes



int main(int argc, const char * argv[]) {
    cout << "Lab #9 by Habeeb Awolumate - \n"
        << "Part 2\n\n";
    NodePtr head = NULL;
        head_insert(head, "Tea", 2);
        head_insert(head, "Jam", 3);
        head_insert(head, "Rolls", 10);
    
    if(search(head, "Tea") == NULL ) // we check this first because the function could return NULL
        cout << "Tea is not in the List" << endl;
    else if(search(head, "Tea") -> item == "Tea"){
        cout << "Tea is in the list" << endl;
    }
    show_list(head);

    
    return 0;
}

//function definitions

//search function definition
NodePtr search(NodePtr head, string an_item){
    NodePtr here = head;
    if (here == NULL){
        return NULL;
    }
    while( here -> item != an_item &&  here -> Next != NULL){
        here = here-> Next;
    }
    if(here -> item == an_item)
        return here;
    else
        return NULL;
   
}




//heads_insert function definition
void head_insert(NodePtr& head, string an_item, int a_number){
    NodePtr temp = new Node;
    temp -> item = an_item;
    temp -> num = a_number;
    temp -> Next = head;
    head = temp;
}
 //show list function definition
void show_list(NodePtr head){
//    for(NodePtr iter = head; iter -> Next != NULL; iter = iter->Next){
//        cout << iter -> item << " " << iter -> num << endl;
//    }
    while (head != NULL) {
        cout << head -> item << " " << head -> num << endl;
        head = head -> Next;
    }
}

