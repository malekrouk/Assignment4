#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int value;
	int occ = 1;
	node* next;

};


class LL
{

private:
	node* head;

public:
	

		void addNodeAtFront( int v); /*adds a node at the front of the LL*/
		void addNodeAtBack(int value); /*adds a node at the back of the LL*/

		void removeNodeAtFront(); /*removes node from the front of the LL*/

		void print(); /*prints the LL*/

		int sumOfNodes(); /*returns the sum of all values in the LL*/

		void addocc(int v); /*gives each node its value's occurance from the vector*/
		void createLLFromVector(vector<int> v); /*explained in the report*/

	
};

