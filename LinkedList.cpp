/**********************************************************
*	Program to demonstrate Linked List using OOP concepts
*	author: Shubham Singh
**********************************************************/

#include<iostream>

template<typename T>
class List
{
		struct node
		{
			T data;
			node *next;
		};
		node *head, *tail;
		size_t size_;
	public:
		List();
		List(size_t _size);
		void insert(T value);
		T& operator[](size_t index);
		size_t size();
};

//Creates empty list
template<typename T>
List<T>::List() : head(nullptr), tail(nullptr), size_(0){}

//Creates list of size _size and initialize every element with 0
template<typename T>
List<T>::List(size_t _size) : head(nullptr), tail(nullptr), size_(0)
{
	while(size_ != _size)
		insert(0);
}

//Inserts an element at back of the list
template<typename T>
void List<T>::insert(T value)
{
	size_++;
	node *newNode = new node;
	newNode->data = value;
	newNode->next = nullptr;
	if(head == nullptr)
		head = tail = newNode;				
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}	
}

//Returns value at passed index and returns value at last of the list if index is out of range
template<typename T>
T& List<T>::operator[](size_t index)
{
	size_t count = 0;
	node *ptr = head;
	//Iterate till count becomes equal to index or count < size of the list
	while(count != index && count < size_)
	{
		ptr = ptr->next;
		count++;
	}
	return count < size_ ? ptr->data : tail->data;
}

//Returns size of the list
template<typename T>
size_t List<T>::size()
{
	return size_;
}

//Driver function
int main()
{
	List<int> l;
	List<float> ll(10);
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	std::cout<<l[-1]<<std::endl;
	std::cout<<"Size l = "<<l.size()<<std::endl;
	std::cout<<"Size ll = "<<ll.size()<<std::endl;
	ll[5] = 1.2f;
	ll[5]++;
	std::cout<<ll[5]<<std::endl;
	return 0;
}
