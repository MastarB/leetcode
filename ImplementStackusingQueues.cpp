#include<queue>
class Stack {
public:
    // Push element x onto stack.
    void push(int x) 
	{
    	que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() 
	{
        for(int i = 1; i < que.size(); ++i)
        {
        	que.push(que.front());
        	que.pop();
		}
		que.pop();
    }

    // Get the top element.
    int top() 
	{
		if(que.empty())
			exit(1);
        for(int i = 1; i < que.size(); ++i)
        {
        	que.push(que.front());
        	que.pop();
		}
		int tmp = que.front();
		que.push(tmp);
		que.pop();
		return tmp;
    }

    // Return whether the stack is empty.
    bool empty() 
	{
        return que.empty();
    }
    
private:
	queue<int>que;
};
