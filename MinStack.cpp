#include<iostream>
using namespace std;

class MinStack {
public:
	MinStack()
	{
		cap = 1;
		size = 0;
		ints = new int[cap];
		ep = NULL;
		mp = NULL;
		mins = new int[cap];
	}
    void push(int x) 
	{
        if(size == cap)
        {
        	cap *= 2;
        	int* tmp = new int[cap];
        	int* mtmp = new int[cap];
        	for(int i = 0;i < size; i++)
        	{
				mtmp[i] = mins[i];
        		tmp[i] = ints[i];
        	}
        	delete ints;
        	delete mins;
        	ints = tmp;
        	mins = mtmp;
		}
		ints[size] = x;
		if(size == 0)mins[size] = x;
		else mins[size] = min(x,mins[size-1]);
		ep = ints+size;
		mp = mins+size;
		size++;
    }

    void pop() 
	{
        size--;
        if(size < cap/2)
        {
        	cap /= 2;
        	int* tmp = new int[cap];
        	int* mtmp = new int[cap];
        	for(int i = 0;i < size; i++)
        	{
				tmp[i] = ints[i];
				mtmp[i] = mins[i];
			}
        	delete ints;
        	delete mins;
        	ints = tmp;
        	mins = mtmp;
		}
		if(size == 0)
		{
			ep = NULL;
			mp = NULL;
		}
        else 
		{
			ep = ints+(size-1);
			mp = mins+(size-1);
		}
    }

    int top() 
	{
		if(ep != NULL)return *ep;
		exit(0);
    }

    int getMin() 
	{
        if(mp != NULL)return *mp;
		exit(1);
    }
    
    int min(int a, int b)
    {
    	return a > b ? b : a;
	}
private:
	int cap;//the space allocated by the memory
	int size;//the number of the elements
	int* ep;//pointer of the top element;
	int* mp;//pointer of the min element;
	int* ints;//element array
	int* mins;//min arr;
};

int main()
{
	MinStack stk;
	stk.push(-3);
	cout<<stk.getMin();
}
