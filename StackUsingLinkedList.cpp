#include<iostream>

using namespace std;

#define MAX 50//Change this value to change default value of capacity

struct node
{
    int data;
    struct node *next;
};

class MyStack
{
    private:
        node *top;
        int capacity;
        int size;
    public:
        //Default constructor
        MyStack() : top(nullptr), capacity(MAX), size(0){}
        //Parametrized constructor
        MyStack(int c) : top(nullptr), capacity(c), size(0){}
        //Copy constructor
        MyStack(const MyStack &obj)
        {
            this->capacity = obj.capacity;
            this->size = obj.size;
            this->top = obj.top;
        }
        //Push operation function
        void push(const int &val)
        {
            cout<<"Push "<<val<<endl;
            if(is_full())//If stack is full
            {
                cout<<"Cannot push "<<val<<". Stack overflow!\n";
                return;
            }
            node *newNode = new node;//Create new node
            newNode->data = val;//Add value to the new node
            if(top == nullptr)//If stack is empty
                newNode->next = nullptr;//Then, the node's next will not point to any other node
            else
                newNode->next = top;
            top = newNode;//Elements are pushed at top of the stack
            size++;//Increment size
        }
        //Pop operation function
        void pop()
        {
            if(is_empty())//If stack is empty
            {
                cerr<<"Cannot pop. Stack UnderFlow!\n";//Print error to error stream
                return;
            }
            node *temp = top;
            int val = top->data;
            top = temp->next;//Make top point to next element in stack
            delete temp;//Release memory
            size--;//Decrement size
            cout<<"Pop "<<val<<endl;
        }
        
        //Function to check if stack is full or not
        bool is_full() const
        {
            if(size == capacity)//If size reaches to capacity
                return true;
            else
                return false;
        }
        
        //Function to check if stack is empty or not
        bool is_empty() const
        {
            if(size == 0)
                return true;
            else
                return false;
        }
        
        //Clear operation function
        void clear()
        {
            while(!is_empty())//Keep popping till stack becomes empty
                pop();
        }
        
        //Function to display stack from top to bottom
        void display() const
        {
            cout<<"Stack from top to bottom: ";
            node *ptr = top;
            while(ptr != nullptr)
            {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
        
        //Destructor to empty stack and free all allocated memory
        ~MyStack()
        {
            clear();
        }
};

//main function to demonstrate MyStack class
int main()
{
    MyStack a(4);
    //Push values into stack
    cout<<"Testing stack:-\n";
    a.pop();
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.pop();
    a.push(6);
    a.pop();
    a.display();
    cout<<"Destructor called\n";
    return 0;
}
