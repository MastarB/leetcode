#include<iostream>
using namespace std;

/* Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
    	if(head == NULL)return head;
    	ListNode* c = head;
    	int count = 0;
    	while(c != NULL)
    	{
    		count++;
    		c = c->next;
		}
    	ListNode* p = head;
 		for(int i = 0; i < k%count; i++)
		{
			if(p->next != NULL)
				p = p->next;
			else p = head;	
		}
		if(p == head)return head;
		ListNode* newtail = head;
		while(p->next != NULL)
		{
			p = p->next;
			newtail = newtail->next;
		}
		p->next = head;
		head = newtail->next;
		newtail->next = NULL;
		return head;
		       
    }
};
