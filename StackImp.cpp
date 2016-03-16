#include<iostream>
using namespace std;
class Stack {
public:
	Stack():size(0),cap(1)
	{
		p = new int[cap];
	}
    // Push element x onto stack.
    void push(int x) 
	{
        if(size == cap)
        {
        	int *newp = new int[cap*=2];
        	for(int i = 0; i < size; ++i)
        		newp[i] = p[i];
			delete p;
			p = newp;
		}
		p[size++] = x;
    }

    // Removes the element on top of the stack.
    void pop() 
	{
		if(size == 0)
			cout<<"fuck u SillyB";
        if(--size == cap/2)
        {
        	int *newp = new int[cap/=2];
        	for(int i = 0; i < size; ++i)
        		newp[i] = p[i];
			delete p;
			p = newp;
		}
    }

    // Get the top element.
    int top()
	{
		if(size == 0)
			cout<<"fuck u SillyB";
        return p[size-1];
    }

    // Return whether the stack is empty.
    bool empty() 
	{
        return size == 0;
    }
    
private:
	int* p;
	int cap;
	int size;
	
};
