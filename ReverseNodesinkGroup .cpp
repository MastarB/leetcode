/**
 * Definition for singly-linked list.
 */
#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if(head == NULL)return NULL;
        ListNode* p = head;
        bool sethead = false;
        bool could = true;
        stack<ListNode*>befores;
        ListNode* former;
        while(could)
        {
        	int n = k;
        	while(p !=NULL&&n)
        	{
        		befores.push(p);
        		p = p->next;
        		n--;
			}
			if(n != 0)could = false;
			if(could)
			{
				
				ListNode* temp = befores.top();
				while (befores.size()>1)
				{
					ListNode*get = befores.top();
					befores.pop();
					get->next =befores.top();
				}
				ListNode* guard = befores.top();
				befores.pop();
				guard->next = p;
				if(sethead)
				{
					former->next = temp;
				}
				else
				{
					head = temp;
					sethead = true;
				}
				former = guard;
			
			}
			
			
		}
		return head;
        
    	
    }
   
};
int main()
{
	int n = 12;
	ListNode * head;
	head = new ListNode(0);
	ListNode * p =head;
	
	while(n--)
	{
		head->next = new ListNode(12-n);
		head = head->next;
	}
	
	Solution so;
	p = so.reverseKGroup(p,1);
	while (p != NULL)
	{
		cout<<p->val<<' ';
		p = p->next;
	}
	
}
