/**********************************************************
*	Program to demonstrate Linked List using OOP concepts
*	author: Shubham Singh
**********************************************************/

#include<iostream>

using namespace std;

//List ADT class definition
class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
		};
		Node *head;
	public:
		List() : head(nullptr){}
		void insertLL(int value);
		void deleteLL(int value);
		bool searchLL(int value);
		void printLL();
};

//Inserts an element at back of the list
void List::insertLL(int value)
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;
	if(head == nullptr)
		head = newNode;				
	else
	{
		Node *ptr = head;
		while(ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = newNode;
	}	
}

//Deletes a value from the list, if present.
void List::deleteLL(int value)
{
	Node *pre = nullptr;
	Node *cur = head;
	
	while(cur != nullptr && cur->data != value)
	{
		pre = cur;
		cur = cur->next;
	}
	
	if(cur == nullptr)//If value not found in list
	{
		cout<<value<<" not found in the list"<<endl;
		return;
	}
	
	if(cur == head)//If value is first in the list
		head = head->next;
	else
		pre->next = cur->next;
	delete cur;//Free memory allocated for the node
}

//Searchs for a value in the list and if found returns true otherwise false
bool List::searchLL(int value)
{
	Node *ptr = head;
	while(ptr != nullptr && ptr->data != value)
		ptr = ptr->next;
	
	if(ptr == nullptr)//If value not found in the list
		return false;
	
	return true;
}

//Prints content of list
void List::printLL()
{
	Node *ptr = head;
	while(ptr != nullptr)
	{
		if(ptr->next == nullptr)
			cout<<ptr->data<<endl;
		else
			cout<<ptr->data<<" -> ";
		ptr = ptr->next;
	}
}

//Driver function to test above list
int main()
{
	List l;
	l.insertLL(1);
	l.insertLL(2);
	l.insertLL(3);
	l.insertLL(4);
	l.insertLL(5);
	l.insertLL(6);
	l.insertLL(7);
	l.insertLL(8);
	l.insertLL(9);
	l.insertLL(10);
	
	cout<<"List after inserting 1, 2, 3, 4, 5, 6, 7, 8, 9 and 10: ";
	l.printLL();
	
	l.deleteLL(1);
	l.deleteLL(6);
	l.deleteLL(10);
	
	cout<<"\nList after deleting 1, 6 and 10: ";
	l.printLL();
	cout<<"\nTrying to delete 10 again: ";
	l.deleteLL(10);
	
	if(l.searchLL(5))
		cout<<"\n5 is present in the list"<<endl;
	else
		cout<<"\n5 is NOT present in the list"<<endl;
	
	if(l.searchLL(10))
		cout<<"\n10 is present in the list"<<endl;
	else
		cout<<"\n10 is NOT present in the list"<<endl;
	return 0;
}
