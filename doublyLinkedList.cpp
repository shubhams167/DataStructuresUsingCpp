#include<iostream>
#include<fstream>

using namespace std;

class List
{
	struct Node{
		int data;
		Node *left, *right;
		//Constructor
		Node(int n, Node* l, Node* r) : data(n), left(l), right(r){} 
	} *head, *tail;
	
	public:
		List() : head(nullptr), tail(nullptr){}
		//Function to insert elements into the list
		void insert(const int& num)
		{
			if(head == nullptr)	//When list is empty
			{
				head = new Node(num, nullptr, nullptr);//Create new Node and pass parameters into the constructor of Node
				tail = head;
			}
			else
			{
				Node *newNode = new Node(num, tail, nullptr);//Create new Node and pass parameters into the constructor of Node
				tail->right = newNode;
				tail = newNode;
			}
		}
		//Function to write current list into output.txt
		void writeList()
		{
			ofstream f("output.txt", ios::out);
			Node *ptr = head;
			while(ptr != nullptr)
			{
				f<<ptr->data<<" ";
				ptr = ptr->right;
			}
			f.close();
		}
		//Function to create the list from input.txt
		void createList()
		{
			ifstream f("input.txt", ios::in);
			int num;
			while(!f.eof())
			{
				f>>num;
				insert(num);
			}
			f.close();
		}
		//Function to delete a node from the list
		void deleteNode(Node *_node)
		{
			if(_node == head && _node == tail)	//When _node is the only node in the list
			{
				delete _node;
				head = tail = nullptr;
			}
			else
			if(_node == head)	//When _node is the head node
			{
				head->right->left = nullptr;
				head = head->right;
				delete _node;
			}
			else
			if(_node == tail)	//When _node is the tail node
			{
				tail->left->right = nullptr;
				tail = tail->left;
				delete _node;
			}
			else	//When _node is a node in somewhere middle of the list
			{
				_node->left->right = _node->right;
				_node->right->left = _node->left;
				delete _node;
			}
		}
		//Function to delete a node from the list from the beginning
		void deleteFromHead()
		{
			int nodeNum, count = 1;
			cout<<"Which item do you want to delete from the beginning? ";
			cin>>nodeNum;
			Node *ptr = head;
			while(count != nodeNum && ptr != nullptr)
			{
				count++;
				ptr = ptr->right;
			}
			deleteNode(ptr);
		}
		//Function to delete a node from the list from the end
		void deleteFromTail()
		{
			int nodeNum, count = 1;
			cout<<"Which item do you want to delete end? ";
			cin>>nodeNum;
			Node *ptr = tail;
			while(count != nodeNum && ptr != nullptr)
			{
				count++;
				ptr = ptr->left;
			}
			deleteNode(ptr);
		}
};

int main()
{
	List l;
	l.createList();
	l.deleteFromHead();
	l.deleteFromTail();
	l.writeList();
	return 0;
}
