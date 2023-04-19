#include "LL.h"
#include <iostream>
#include <vector>
using namespace std;


void LL::addNodeAtFront(int v)
{

    if (head != nullptr) /*checking if pointer head is empty or not*/
    {
        node* addednode = new node; /*if it is not empty then move it by one infront and put the new node in th the front as the head*/
        addednode->value = v;
        addednode->next = NULL;
        head = addednode;
       
    }
    else /*if it is empty then fill it*/
    {
        head = new node;
        head->value = v;
        head->next = NULL;
    }
}

void LL::addNodeAtBack(int value)
{
    node* temp;
    node* addednode = new node;
    addednode->value = value;
    addednode->next = NULL;
    temp = head;
    while (temp->next != NULL) /*run till temp is the last node */
    {
        temp = temp->next;
    }
    temp->next = addednode; /*make temp point to a new last node */
}

void LL::removeNodeAtFront()
{
    node* del = head; 
    head = head->next; /*move head one step infront */
    del->value = NULL; /*delete the one step behind*/
    del->next = NULL;
    delete del;
   
}
//Node* temp = head;
//
//// Check for empty list.
//if (head == NULL) {
//    cout << "List empty" << endl;
//    return;
//}
//
//// Traverse the list.
//while (temp != NULL) {
//    cout << temp->data << " ";
//    temp = temp->next;
//}
void LL::print()
{
    node* temp = head;
    if (head == NULL) /*check if empty*/
    {
        cout << "NULL" << endl;
    }
    else
    {
        while (temp != NULL) /*iterate the linked list*/
        {
            cout << temp->value << endl; /*print*/
            temp = temp->next; /* move on to next node*/
        }
    }

}
int LL::sumOfNodes()
{
    int sum = 0; /*sum starts at zero*/

    node* temp = head;

    if (head == NULL) /*check if empty*/
    {
        cout << "NULL" << endl;
    }
    else
    {
        while (temp!= NULL) /*iterate the linked list*/
        {
            sum += temp->value; /*add value in current node to sum*/
            temp = temp->next;/* move on to next node*/
        }
    }
    return sum;
}

void LL::addocc(int v) 
{
    node* temp = head;
    while (temp->next != NULL) /*iterate the linked list*/
    {
        temp=temp->next; /* move on to next node*/
    }
    temp->occ = v; /*update node's occurance value*/

}

void LL::createLLFromVector(vector<int> v)
{

   
    for (int i = 0; i<int(v.size()); i++) /*loop over vector from beginning to end*/
    {
        int counter = 0; /*resets to 0 every time value of the index of the vector being checked for repetitive values in the vector changes*/
        for (int j = i + 1;j<int(v.size());j++) /*loop over vector from begining+1 to end*/
        {
            if (v.at(i) == v.at(j)) /*checking for repetitive values*/
                counter++; /*if found increment counter*/
            v.erase(v.begin() + j); /*and erase the repetitive value using erase(int index) + v.begin() that gives index of the first value oin the vector*/
        }
        if (counter == 0 && i == 0) /*add a node to the LL at the front if it is the first node. Plus, do not adjust occurance if counter=1 since it was not repeated*/
          addNodeAtFront( v.at(i));
         
        if (counter == 0 && i != 0) /*add a node to the LL at the back. Plus, do not adjust occurance if counter=1 since it was not repeated*/
          addNodeAtBack(v.at(i));


        if (counter > 0 && i == 0) /*add a node to the LL at the front if it is the first node. Plus, adjust occurance since it is repeated more than once*/
        {
          addNodeAtFront( v.at(i));
           addocc(counter);

        }

        if (counter > 0 && i != 0) /*add a node to the LL at the back. Plus, adjust occurance since it is repeated more than once*/
        {
          addNodeAtBack(v.at(i));
          addocc(counter);
        }
       
    }

}